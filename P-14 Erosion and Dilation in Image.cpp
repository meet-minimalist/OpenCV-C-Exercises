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

	String originalWindow = "Original Image";
	namedWindow(originalWindow, WINDOW_NORMAL);
	resizeWindow(originalWindow, image.cols / 4, image.rows / 4);
	imshow(originalWindow, image);

	String erode3x3 = "Erosion with 3x3 filter";
	namedWindow(erode3x3, WINDOW_NORMAL);
	resizeWindow(erode3x3, image.cols / 4, image.rows / 4);
	Mat erosion3x3;
	erode(image, erosion3x3, getStructuringElement(MORPH_RECT, Size(3, 3)));
	imshow(erode3x3, erosion3x3);

	String erode5x5 = "Erosion with 5x5 filter";
	namedWindow(erode5x5, WINDOW_NORMAL);
	resizeWindow(erode5x5, image.cols / 4, image.rows / 4);
	Mat erosion5x5;
	erode(image, erosion5x5, getStructuringElement(MORPH_RECT, Size(5, 5)));
	imshow(erode5x5, erosion5x5);

	String dilate3x3 = "Dilation with 3x3 filter";
	namedWindow(dilate3x3, WINDOW_NORMAL);
	resizeWindow(dilate3x3, image.cols / 4, image.rows / 4);
	Mat dilation3x3;
	dilate(image, dilation3x3, getStructuringElement(MORPH_RECT, Size(3, 3)));
	imshow(dilate3x3, dilation3x3);

	String dilate5x5 = "Dilation with 5x5 filter";
	namedWindow(dilate5x5, WINDOW_NORMAL);
	resizeWindow(dilate5x5, image.cols / 4, image.rows / 4);
	Mat dilation5x5;
	dilate(image, dilation5x5, getStructuringElement(MORPH_RECT, Size(5, 5)));
	imshow(dilate5x5, dilation5x5);
	create
	waitKey(0);
	destroyAllWindows();
	return 0;
}