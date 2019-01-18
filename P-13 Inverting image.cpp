#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\IMG-20181018-WA0014.jpg");

	if (image.empty()) {
		cout << "Error in reading image file." << endl;
		cin.get();
		return -1;
	}

	String originalWindow = "Original";
	namedWindow(originalWindow, WINDOW_NORMAL);
	resizeWindow(originalWindow, image.cols / 2, image.rows / 2);
	imshow(originalWindow, image);

	bitwise_not(image, image);
	String invertWindow = "Inverted image";
	namedWindow(invertWindow, WINDOW_NORMAL);
	resizeWindow(invertWindow, image.cols / 2, image.rows / 2);
	imshow(invertWindow, image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}