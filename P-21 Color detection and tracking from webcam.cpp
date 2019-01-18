#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cout << "Error in connecting to the webcam." << endl;
		cin.get();
		return -1;
	}

	String controlWindow = "Controls";
	namedWindow(controlWindow, WINDOW_AUTOSIZE);

	int iLowH = 0;
	int iHighH = 179;
	int iLowS = 0;
	int iHighS = 255;
	int iLowV = 0;
	int iHighV = 255;

	createTrackbar("Low Hue", controlWindow, &iLowH, 179);
	createTrackbar("High Hue", controlWindow, &iHighH, 179);
	createTrackbar("Low Saturation", controlWindow, &iLowS, 255);
	createTrackbar("High Saturation", controlWindow, &iHighH, 255);
	createTrackbar("Low Value", controlWindow, &iLowV, 255);
	createTrackbar("High Value", controlWindow, &iHighV, 255);

	int iLastX = -1;
	int iLastY = -1;

	Mat tempImg;
	cap.read(tempImg);

	Mat imgLines = Mat::zeros(tempImg.size(), CV_8UC3);

	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);
		if (bSuccess == false) {
			cout << "Error in reading frame from webcam." << endl;
			break;
		}
		
		Mat hsvImage;
		cvtColor(frame, hsvImage, COLOR_BGR2HSV);

		Mat thresholdImage;
		inRange(hsvImage, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), thresholdImage);

		// Opening
		erode(thresholdImage, thresholdImage, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(thresholdImage, thresholdImage, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(thresholdImage, thresholdImage, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(thresholdImage, thresholdImage, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		Moments _moments = moments(thresholdImage);

		double m_10 = _moments.m10;	// x moment
		double m_01 = _moments.m01;  // y moment
		double m_00 = _moments.m00;  // zeroth moment of pixel intensity: sum of all the intensities 

		// m_00 is area; if area is less than 10000 than it is surely a noise.
		if (m_00 > 10000) {
			int posX = m_10 / m_00;
			int posY = m_01 / m_00;
			if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0) {
				line(imgLines, Point(iLastX, iLastY), Point(posX, posY), Scalar(255, 0, 0), 8);
			}
			iLastX = posX;
			iLastY = posY;
		}

		frame = frame + imgLines;
		imshow("Original Stream", frame);
		imshow("After applying thresholding, opening and closing operation", thresholdImage);
	
		if (waitKey(10) == 27) {
			cout << "Stopping webcam." << endl;
			break;
		}
	}
	return 0;
}