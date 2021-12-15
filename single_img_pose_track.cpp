#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/cuda.hpp>
#include <iostream>

using namespace cv;



#define POSE_COCO_COLORS_RENDER_GPU \
	255.f, 0.f, 85.f, \
	255.f, 0.f, 0.f, \
	255.f, 85.f, 0.f, \
	255.f, 170.f, 0.f, \
	255.f, 255.f, 0.f, \
	170.f, 255.f, 0.f, \
	85.f, 255.f, 0.f, \
	0.f, 255.f, 0.f, \
	0.f, 255.f, 85.f, \
	0.f, 255.f, 170.f, \
	0.f, 255.f, 255.f, \
	0.f, 170.f, 255.f, \
	0.f, 85.f, 255.f, \
	0.f, 0.f, 255.f, \
	255.f, 0.f, 170.f, \
	170.f, 0.f, 255.f, \
	255.f, 0.f, 255.f, \
	85.f, 0.f, 255.f


/*
convert image to proper format
*/

Mat getImage(const Mat& im, Size baseSize = Size(656, 368), float* scale = 0){
	int w = baseSize.width;
	int h = baseSize.height;
	int nh = h;
	float s = h / (float)im.rows;;
	int nw = im.cols * s;

	if (nw > w){
		nw = w;
		s = w / (float)im.cols;
		nh = im.rows * s;
	}

	if (scale)*scale = 1 / s;
	Rect dst(0, 0, nw, nh);
	Mat bck = Mat::zeros(h, w, CV_8UC3);
	resize(im, bck(dst), Size(nw, nh));
	return bck;
}