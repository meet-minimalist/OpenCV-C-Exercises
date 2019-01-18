#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat image;

void changeBrightness(int bValue, void *usrData) {
	Mat dst;
	int cValue = *(static_cast<int*>(usrData));

	int actualBrightness = bValue - 50;
	double actualContrast = cValue / 50.0;
	cout << "Change Brightness called: Contrast: " << actualContrast << " Brightness: " << actualBrightness << endl;
	image.convertTo(dst, -1, actualContrast, actualBrightness);
	imshow("My Window", dst);
}

void changeContrast(int cValue, void *usrData) {
	Mat dst;
	int bValue = *(static_cast<int*>(usrData));

	int actualBrightness = bValue - 50;
	double actualContrast = cValue / 50.0;
	cout << "Change Brightness called: Contrast: " << actualContrast << " Brightness: " << actualBrightness << endl;
	image.convertTo(dst, -1, actualContrast, actualBrightness);
	imshow("My Window", dst);
}

int main() {
	image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\Best pic_opencv.jpg");

	if (image.empty()) {
		cout << "Error in reading image file." << endl;
		cin.get();
		return -1;
	}

	String window = "My Window";
	namedWindow(window, WINDOW_NORMAL);
	resizeWindow(window, image.cols / 4, image.rows / 4);

	int iBrightness = 50;
	int iContrast = 50;

	createTrackbar("Brightness", window, &iBrightness, 100, changeBrightness, &iContrast);
	createTrackbar("Contrast", window, &iContrast, 100, changeContrast, &iBrightness);

	imshow(window, image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}