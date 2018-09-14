#include <opencv2/opencv.hpp>

using namespace cv;
class GenerateTests{
public:
    int generate(){
        VideoWriter tofile("test1_0.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(0,0,0);
            tofile << frame;
        }
        tofile.release();

        tofile = VideoWriter("test1_1.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(255,255,255);
            tofile << frame;
        }
        tofile.release();
        
        tofile = VideoWriter("test2_0.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(200,200));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(200, 200, CV_8UC3);
            frame = Scalar(0,0,0);
            tofile << frame;
        }
        tofile.release();
        
        tofile = VideoWriter("test2_1.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(255,255,255);
            tofile << frame;
        }
        tofile.release();
        
        tofile = VideoWriter("test3_0.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(0,0,0);
            tofile << frame;
        }
        tofile.release();
        
        tofile = VideoWriter("test3_1.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<48;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(255,255,255);
            tofile << frame;
        }
        tofile.release();
        
        tofile = VideoWriter("test4_0.avi", CV_FOURCC('M','P','4','2'), 48.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(0,0,0);
            tofile << frame;
        }
        tofile.release();
        
        tofile = VideoWriter("test4_1.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(255,255,255);
            tofile << frame;
        }
        tofile.release();

        tofile = VideoWriter("test5_0.avi", CV_FOURCC('M','P','4','2'), 25.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(255,255,255);
            tofile << frame;
        }
        tofile.release();

        tofile = VideoWriter("test5_1.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<25;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(0,0,0);
            tofile << frame;
        }
        tofile.release();

        tofile = VideoWriter("test6_0.avi", CV_FOURCC('M','P','4','2'), 25.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<25;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(255,255,255);
            tofile << frame;
        }
        tofile.release();

        tofile = VideoWriter("test6_1.avi", CV_FOURCC('M','P','4','2'), 24.0, Size(100,100));
        if(!tofile.isOpened()){
            return -1;
        }
        for(int i=0;i<24;i++){
            Mat frame(100, 100, CV_8UC3);
            frame = Scalar(0,0,0);
            tofile << frame;
        }
        tofile.release();

        return 0;
    }
};

int main(){
    GenerateTests gt;
    return gt.generate();
}
