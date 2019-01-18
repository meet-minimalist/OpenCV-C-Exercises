#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("M:\\Mobile Backup\\Photos\\Diu - A Journey towards self discovery\\Best pic.jpg");
	if (image.empty()) {
		cout << "Could not open or find the image." << endl;
		cin.get();
		return -1;
	}

	String windowName = "My Pic";
	namedWindow(windowName, 2); // creates a window
	int h = image.rows / 4;		// to find height of the image
	int w = image.cols / 4;		// to find width of the image
	resizeWindow(windowName, w, h);	// resizes the given window
	imshow(windowName, image);		// displays the image in the given window object, if window object is not created then imshow will create one itself.
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}
