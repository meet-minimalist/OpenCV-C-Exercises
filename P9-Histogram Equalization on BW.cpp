#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\Best pic_opencv.jpg");
	
	if (image.empty()) {
		cout << "Error in reading image file." << endl;
		cin.get();
		return -1;
	}

	String colorWindow = "Colored Image";
	namedWindow(colorWindow, WINDOW_NORMAL);
	resizeWindow(colorWindow, image.cols / 4, image.rows / 4);
	imshow(colorWindow, image);

	cvtColor(image, image, COLOR_BGR2GRAY);
	String bwWindow = "Black and white image";
	namedWindow(bwWindow, WINDOW_NORMAL);
	resizeWindow(bwWindow, image.cols / 4, image.rows / 4);
	imshow(bwWindow, image);

	Mat hist_equalized_image;
	equalizeHist(image, hist_equalized_image);

	String histWindow = "Histogram equalized image";
	namedWindow(histWindow, WINDOW_NORMAL);
	resizeWindow(histWindow, hist_equalized_image.cols / 4, hist_equalized_image.rows / 4);
	imshow(histWindow, hist_equalized_image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}