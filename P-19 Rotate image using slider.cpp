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

	String window = "My Image";
	namedWindow(window, WINDOW_NORMAL);
	resizeWindow(window, image.cols / 4, image.rows / 4);
	
	int iAngle = 180;
	createTrackbar("Angle", window, &iAngle, 360);

	while (true) {
		Mat matRotation = getRotationMatrix2D(Point(image.cols / 2, image.rows / 2), (iAngle - 180), 1);
	
		Mat imgRotated;
		warpAffine(image, imgRotated, matRotation, image.size());
		imshow(window, imgRotated);

		if (waitKey(10) == 27) {
			break;
		}
	}
	return 0;
}