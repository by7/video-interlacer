#include "DualVideoInput.h"
#include <stdio.h>
using namespace cv;

void DualVideoInput::invertColor(Mat m){
    #pragma omp for
    for(int i = 0; i < m.rows; i++)
        for(int j = 0; j < m.cols; j++)
            m.at<uchar>(i,j) = ~m.at<uchar>(i,j);
}

int DualVideoInput::input(VideoCapture cap, int inputNum){
    Mat frame;
    Mat blackwhite;
    while(!done && cap.read(frame)){
        cvtColor(frame, blackwhite, COLOR_BGR2GRAY);
        invertColor(blackwhite);
        sem[inputNum].wait(0);
        outputframe[inputNum] = blackwhite;
        sem[inputNum].notify(0);
    }
    done = true;
    return 0;
}

void DualVideoInput::start(VideoCapture cap1, VideoCapture cap2){
    input1 = std::thread(&DualVideoInput::input, this, cap1, 0);
    input2 = std::thread(&DualVideoInput::input, this, cap2, 1);
}

DualVideoInput::~DualVideoInput(){
    input1.join();
    input2.join();
}

Mat DualVideoInput::getNext(){
    Mat m;
    int inputNum = curr_frame%2;
    if(done && inputNum==0){
        sem[0].notify(1); //free waiting threads
        sem[1].notify(1);
        return m; //return empty Mat
    }
    sem[inputNum].notify(1);
    sem[inputNum].wait(1);
    m = outputframe[inputNum].clone();

    curr_frame++;
    return m;
}

int DualVideoInput::frameCount(){
    return curr_frame;
}
