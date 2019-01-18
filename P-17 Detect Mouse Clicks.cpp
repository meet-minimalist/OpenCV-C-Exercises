#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void onMouseEvent(int event, int x, int y, int flags, void *usrData) {
	if (event == EVENT_LBUTTONDOWN) {
		cout << "Left button of mouse is clicked. Location = (X: " << x << " Y: " << y << ")" << endl;
	}
	else if (event == EVENT_RBUTTONDOWN) {
		cout << "Right button of mouse is clicked. Location = (X: " << x << " Y: " << y << ")" << endl;
	}
	else if (event == EVENT_MBUTTONDOWN) {
		cout << "Middle button of mouse is clicked. Location = (X: " << x << " Y: " << y << ")" << endl;
	}
	else if(event == EVENT_MOUSEMOVE) {
		cout << "Mouse move over the window. Location = (X: " << x << " Y: " << y << ")" << endl;
	}
}

int main() {
	Mat image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\Best pic_opencv.jpg");
	if (image.empty()) {
		cout << "Error in reading image file." << endl;
		cin.get();
		return -1;
	}
	
	String window = "My Image";
	namedWindow(window, WINDOW_NORMAL);
	resizeWindow(window, image.cols / 4, image.rows / 4);
	
	setMouseCallback(window, onMouseEvent, NULL);
	imshow(window, image);
	
	waitKey(0);
	destroyAllWindows();
	return 0;
}