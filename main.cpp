#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/cuda.hpp>
#include <openpose>
#include <iostream>


using namespace std;
using namespace cv;

int main(){
    Mat myMat = imread("images/rose_vs_zhang.png");
    Mat result; //apparently declaring this first before use saves memory/increases speed

    PoseEstimator model;
    model.load("/usr/share/opencv/haarcascades/haarcascade_frontalcatface.xml");
    
    model.predict(MyMat, result);
    return 0;

}