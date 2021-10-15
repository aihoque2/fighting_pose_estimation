#include <opencv4/opencv2/objdetect.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/objdetect.hpp>
#include <opencv4/opencv2/core/cuda.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(){

    vector<Rect> faces;
    Mat img, gray;
    img = imread("imagesammar.jpg");


    CascadeClassifier cascade;
    cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalcatface.xml");
    
    cascade.detectMultiScale(img, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30,30));
    cout << "we detected our objects. yay" << endl;
    rectangle(img, faces[0], Scalar(255,0,0));

    imshow("display window", img);
    waitKey(0);

    return 0;
}