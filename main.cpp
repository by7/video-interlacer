#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "DualVideoInput.h"

using namespace cv;

//find smallest size that fits both videos
Size getSize(VideoCapture cap1, VideoCapture cap2){
    int width = std::max(cap1.get(CV_CAP_PROP_FRAME_WIDTH),cap2.get(CV_CAP_PROP_FRAME_WIDTH));
    int height = std::max(cap1.get(CV_CAP_PROP_FRAME_HEIGHT),cap2.get(CV_CAP_PROP_FRAME_HEIGHT));
    return Size(width, height);
}

//calculate fps such that interlaced video is length of shortest video
double getFps(VideoCapture cap1, VideoCapture cap2){
    double fps;
    double fps1 = cap1.get(CV_CAP_PROP_FPS);
    double fps2 = cap2.get(CV_CAP_PROP_FPS);
    double len1 = cap1.get(CV_CAP_PROP_FRAME_COUNT)/fps1;
    double len2 = cap2.get(CV_CAP_PROP_FRAME_COUNT)/fps2;
    if(len1<len2)
        fps = 2*fps1;
    else fps = 2*fps2;
    return fps;
}

int main(int argc, char** argv )
{
    if(argc != 3){
        printf("usage: DisplayImage <Video_Path> <Video_Path2>\n");
        return -1;
    }
    VideoCapture cap1(argv[1]);
    if(!cap1.isOpened()){
        return -1;
    }
    VideoCapture cap2(argv[2]);
    if(!cap2.isOpened()){
        return -1;
    }
    DualVideoInput vi;
    vi.start(cap1, cap2);
    Size size = getSize(cap1, cap2);
    double fps = getFps(cap1, cap2);
    VideoWriter tofile("output.avi", CV_FOURCC('M','P','4','2'), fps, size);
    if(!tofile.isOpened()){
        return -1;
    }

    Mat frame;
    Mat frame2;
    frame = vi.getNext();
    while(!frame.empty()){
        resize(frame, frame2, size);
        cvtColor(frame2, frame, COLOR_GRAY2BGR);
        tofile << frame;
        frame = vi.getNext();
    }
    printf("%d,%d,%d\n",vi.frameCount(), size.height, size.width);
    tofile.release();
    return 0;
}
