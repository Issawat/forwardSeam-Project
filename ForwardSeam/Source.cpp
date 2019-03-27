#include<stdio.h>
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<math.h>
#include<algorithm>

using namespace std;
using namespace cv;



int main() {
	Mat img = imread("C:\\Users\\user02\\Documents\\forwardSeam-Project\\Debug\\test.jpg",IMREAD_COLOR);
	namedWindow("Forward Seam", WINDOW_AUTOSIZE);
	imshow("Forward Seam", img);
	int c = cvWaitKey(0);
	Size sz = img.size();
	int H = sz.height;
	int W = sz.width;
	

	
	int CL, CU, CR;
	
	

	// ESC = 27 , A = 97, D = 100, S = 115, W = 119

	

	while (c != 27) {
		while (c != 27 && c != 97 && c != 100 && c != 115 && c != 119) {
			c = cvWaitKey(0);
		}

		
		Mat gray;
		int xxx = img.channels();
		printf("%d \n", xxx);

		cvtColor(img, gray, CV_BGR2GRAY);
		Mat eng(H + 2, W + 2, CV_8UC1, Scalar(0));

		Mat M = (Mat_<int>(H, W));
		Mat K = (Mat_<int>(H, W));

		
		copyMakeBorder(gray, eng, 1, 1, 1, 1, BORDER_REPLICATE);




		
		// a d
		if (c == 97 || c == 100) {
			// Prepare horizontal best seam
			
			
			
			for (int i = 0; i < W; i++) {
				
				M.at<int>(0, i) = abs(eng.at<uchar>(0, i) - eng.at<uchar>(0, i + 2));
				// all elements in first row of K matrix are 0
				K.at<int>(0, i) = 0;
				
			}

			
			int ML, MU, MR, k;
			for (int i = 1; i < eng.rows-2; i++) {
				
				for (int j = 0; j < eng.cols-2; j++) {


					CU = abs(eng.at<uchar>(i + 1, j) - eng.at<uchar>(i + 1, j + 2));
					CL = abs(eng.at<uchar>(i + 1, j) - eng.at<uchar>(i + 1, j + 2)) + abs(eng.at<uchar>(i + 1, j) - eng.at<uchar>(i, j + 1));
					CR = abs(eng.at<uchar>(i + 1, j) - eng.at<uchar>(i + 1, j + 2)) + abs(eng.at<uchar>(i + 1, j + 2) - eng.at<uchar>(i, j + 1));

					if (j == 0) {

						
						MU = M.at<int>(i - 1, j) + CU;
						MR = M.at<int>(i - 1, j + 1) + CR;
						M.at<int>(i, j) = min(MU,MR);
						if (MU < MR) {
							k = 2;
						}
						else {
							k = 3;
						}
						
					}
					else if (j == W - 1) {
						
						
						MU = M.at<int>(i - 1, j) + CU;
						ML = M.at<int>(i - 1, j - 1) + CL;
						
						M.at<int>(i, j) = min(MU,ML);
						if (MU < ML) {
							k = 2;
							
						}
						else {
							k = 1;
						}

					}
					else {
						
						ML = M.at<int>(i - 1, j - 1) + CL;
						MU = M.at<int>(i - 1, j) + CU;
						MR = M.at<int>(i - 1, j + 1) + CR;
						M.at<int>(i, j) = min(MU, min(ML, MR));

						

					}

				}
			}

			printf("%d %d \n", H, W);
		}
		// s w
		if (c == 115 || c == 119) {
			// Prepare vertical best seam
			int h = img.rows;
			int w = img.cols;
			printf("[click= %c][%d] \n", c,img.channels());
			printf("%d %d \n", h, w);
		}
		// a
		if (c == 97) {
			Mat img_new(H, --W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 
			
			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();
		}

		//d
		if (c == 100) {
			Mat img_new(H, ++W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 

			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();

		}
		//s
		if (c == 115) {
			Mat img_new(--H, W, CV_64FC3, Scalar(0, 0, 0, 0));
			// Our code 

			imshow("Forward Seam", img_new);
			img.release();
			img = img_new.clone();
			img_new.release();

		}
		//w
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