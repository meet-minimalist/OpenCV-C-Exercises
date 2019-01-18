#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap(0);

	if (cap.isOpened() == false) {
		cout << "Can't open the video camera." << endl;
		cin.get();
		return -1;
	}

	String originalWindow = "Original Stream";
	String blur3x3 = "3x3 Blurred";
	String blur5x5 = "5x5 Blurred";

	namedWindow(originalWindow);
	namedWindow(blur3x3);
	namedWindow(blur5x5);
	
	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);
		if (bSuccess == false) {
			cout << "Video camera is disconnected." << endl;
			cin.get();
			break;
		}
		imshow(originalWindow, frame);

		Mat blurred_image_3x3;
		blur(frame, blurred_image_3x3, Size(3, 3));
		imshow(blur3x3, blurred_image_3x3);

		Mat blurred_image_5x5;
		blur(frame, blurred_image_5x5, Size(5, 5));
		imshow(blur5x5, blurred_image_5x5);

		if (waitKey(10) == 27) {
			cout << "Esc key is pressed by User. Stopping the webcam video." << endl;
			break;
		}
	}
	return 0;
}