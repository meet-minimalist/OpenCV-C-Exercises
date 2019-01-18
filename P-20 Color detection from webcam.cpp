#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cout << "Error in connecting to the webcam." << endl;
		cin.get();
		return -1;
	}

	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 0;


	String controls = "Controls";
	namedWindow(controls, CV_WINDOW_AUTOSIZE);

	createTrackbar("Low Hue", controls, &iLowH, 179);
	createTrackbar("High Hue", controls, &iHighH, 179);

	createTrackbar("Low Saturation", controls, &iLowS, 255);
	createTrackbar("High Saturation", controls, &iHighS, 255);

	createTrackbar("Low Value", controls, &iLowV, 255);
	createTrackbar("High Value", controls, &iHighV, 255);
	
	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "Can't read a frame from webcam." << endl;
			break;
		}

		imshow("Web Cam Stream", frame);

		Mat hsvFrame;
		cvtColor(frame, hsvFrame, COLOR_BGR2HSV);

		Mat imgThreshold;
		inRange(hsvFrame, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThreshold);
		// inRange function will return a black and white image with 255 value for pixels for which the criteria is satisfied and 0 value for other pixels

		imshow("After applying thresholding", imgThreshold);

		// to remove small small white spots we do opening (erosion --> dilation) and then closing (dilation --> erosion)

		// opening will remove the unneccessary white spots in the foreground (unneccesarily detected)
		erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		imshow("After OPENING operation", imgThreshold);

		// closing will remove the unneccessary holes in the foreground detection (unneccesarily detected)
		dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		imshow("After OPENING + CLOSING operation", imgThreshold);

		if (waitKey(10) == 27) {
			cout << "Stopping the webcam." << endl;
			break;
		}

	}

	return 0;
}