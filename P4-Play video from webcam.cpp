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

	double w = cap.get(CAP_PROP_FRAME_WIDTH);
	double h = cap.get(CAP_PROP_FRAME_HEIGHT);

	cout << "Resolution of the video is: " << w << " x " << h << endl;
	String windowName = "Webcam video";
	namedWindow(windowName);

	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);
		if (bSuccess == false) {
			cout << "Video camera is disconnected." << endl;
			cin.get();
			break;
		}
		imshow(windowName, frame);

		if (waitKey(10) == 27) {
			cout << "Esc key is pressed by User. Stopping the webcam video." << endl;
			break;
		}
	}
	return 0;
}