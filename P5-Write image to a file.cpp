#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("M:\\Mobile Backup\\Photos\\Diu - A Journey towards self discovery\\Best pic.jpg");
	if (image.empty()) {
		cout << "Image can't be loaded." << endl;
		cin.get();
		return -1;
	}

	bool bSuccess = imwrite("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\Best pic_opencv.jpg", image);
	if (bSuccess == false) {
		cout << "Error in saving the image file." << endl;
		cin.get();
		return -1;
	}

	String windowName = "Original Image";
	namedWindow(windowName, WINDOW_NORMAL);
	int w = image.cols / 4;
	int h = image.rows / 4;	
	resizeWindow(windowName, w, h);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}