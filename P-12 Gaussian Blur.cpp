#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\IMG_20180805_110029 - Copy.jpg");

	if (image.empty()) {
		cout << "Error in reading image file." << endl;
		cin.get();
		return -1;
	}
	
	String originalWindow = "Original Image";
	namedWindow(originalWindow, WINDOW_NORMAL);
	resizeWindow(originalWindow, image.cols / 4, image.rows / 4);
	imshow(originalWindow, image);

	String gaussianBlurWindow3x3 = "Gaussian Blur 3x3";
	namedWindow(gaussianBlurWindow3x3, WINDOW_NORMAL);
	resizeWindow(gaussianBlurWindow3x3, image.cols / 4, image.rows / 4);
	Mat gaussianBlurImage_3x3;
	GaussianBlur(image, gaussianBlurImage_3x3, Size(9, 9), 0);
	imshow(gaussianBlurWindow3x3, gaussianBlurImage_3x3);

	String gaussianBlurWindow5x5 = "Gaussian Blur 5x5";
	namedWindow(gaussianBlurWindow5x5, WINDOW_NORMAL);
	resizeWindow(gaussianBlurWindow5x5, image.cols / 4, image.rows / 4);
	Mat gaussianBlurImage_5x5;
	GaussianBlur(image, gaussianBlurImage_5x5, Size(15, 15), 0);
	imshow(gaussianBlurWindow5x5, gaussianBlurImage_5x5);

	waitKey(0);
	destroyAllWindows();
	return 0;
}