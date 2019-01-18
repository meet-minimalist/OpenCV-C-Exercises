#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("D:\\Movies\\Call of Duty Infinite Warfare.mp4");

	if (cap.isOpened() == false) {
		cout << "Can't open video file." << endl;
		cin.get();
		return -1;
	}

	// start the video from 10000 millisecond (10 sec)
	cap.set(CAP_PROP_POS_MSEC, 10000);

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per second " << fps << endl;
	String windowName = "My video";
	namedWindow(windowName);
	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "Video completed." << endl;
			cin.get();
			break;
		}
		
		imshow(windowName, frame);

		if (waitKey(10) == 27) {
			cout << "Esc key is pressed by user. Stopping the video." << endl;
			break;
		}
	}
	return 0;
}