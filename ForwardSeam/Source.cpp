#include<stdio.h>
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("C:\\Users\\actiondeveloper1998\\Documents\\forwardSeam-Project\\Debug\\test.jpeg",IMREAD_COLOR);
	namedWindow("Forward Seam", WINDOW_AUTOSIZE);
	imshow("Forward Seam", img);
	int c = cvWaitKey(0);
	Size sz = img.size();
	int H = sz.height;
	int W = sz.width;

	// ESC = 27 , A = 97, D = 100, S = 115, W = 119

	while (c != 27) {
		while (c != 27 && c != 97 && c != 100 && c != 115 && c != 119) {
			c = cvWaitKey(0);
		}
		if (c == 97 || c == 100) {
			// Prepare horizontal best seam
		}
		if (c == 115 || c == 119) {
			// Prepare vertical best seam
		}
		if (c == 97) {
			Mat img_new(H, --W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 

			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();
		}
		if (c == 100) {
			Mat img_new(H, ++W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 

			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();

		}
		if (c == 115) {
			Mat img_new(--H, W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 

			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();

		}
		if (c == 119) {
			Mat img_new(++H, W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 

			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();
		}
		if (c == 27) {
			break;
		}

		c = cvWaitKey(0);
	}

	return 0 ;
}