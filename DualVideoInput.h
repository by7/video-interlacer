#include "Semaphore.h"
#include <opencv2/opencv.hpp>
#include <thread>

class DualVideoInput{
private:
    cv::Mat outputframe[2];
    Semaphore sem[2];
    bool done = false;
    int curr_frame = 0;
    std::thread input1;
    std::thread input2;

    // pixel-by-pixel invert (given grayscale image m)
    void invertColor(cv::Mat m);

    //thread for reading and preliminary processing one video
    int input(cv::VideoCapture cap, int inputNum);
public:
    //start thread
    void start(cv::VideoCapture cap1, cv::VideoCapture cap2);

    //wait for thread to finish
    ~DualVideoInput();

    //return the appropriate next frame (either from video 1 or video 2)
    cv::Mat getNext();

    //return the current frame count
    int frameCount();
};
