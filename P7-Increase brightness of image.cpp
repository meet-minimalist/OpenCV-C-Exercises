#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\Best pic_opencv.jpg");
	
	if (image.empty()) {
		cout << "Can not load the image." << endl;
		cin.get();
		return -1;
	}

	String wName = "My Image";
	namedWindow(wName, WINDOW_NORMAL);
	resizeWindow(wName, image.cols / 4, image.rows / 4);
	imshow(wName, image);

	Mat imageBrightnessHigh50;
	image.convertTo(imageBrightnessHigh50, -1, 1, 100);
	String bPlus50 = "Brightness increased by 100";
	namedWindow(bPlus50, WINDOW_NORMAL);
	resizeWindow(bPlus50, image.cols / 4, image.rows / 4);
	imshow(bPlus50, imageBrightnessHigh50);

	Mat imageBrightnessLow50;
	image.convertTo(imageBrightnessLow50, -1, 1, -100);
	String bMinus50 = "Brightness decreased by 100";
	namedWindow(bMinus50, WINDOW_NORMAL);
	resizeWindow(bMinus50, image.cols / 4, image.rows / 4);
	imshow(bMinus50, imageBrightnessLow50);

	waitKey(0);
	destroyAllWindows();
	return 0;
}