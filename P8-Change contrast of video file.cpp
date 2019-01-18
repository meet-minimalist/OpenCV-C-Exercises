#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap("D:\\Movies\\Call of Duty Infinite Warfare.mp4");

	if (cap.isOpened() == false) {
		cout << "Error in opening video file." << endl;
		cin.get();
		return -1;
	}

	String wName = "My Video";
	namedWindow(wName, WINDOW_NORMAL);
	resizeWindow(wName, cap.get(CAP_PROP_FRAME_WIDTH) / 2, cap.get(CAP_PROP_FRAME_HEIGHT) / 2);

	String cx4 = "Video with contrast increased by 4";
	namedWindow(cx4, WINDOW_NORMAL);
	resizeWindow(cx4, cap.get(CAP_PROP_FRAME_WIDTH) / 2, cap.get(CAP_PROP_FRAME_HEIGHT) / 2);

	String cx0_5 = "Video with contrast decreased by 0.5";
	namedWindow(cx0_5, WINDOW_NORMAL);
	resizeWindow(cx0_5, cap.get(CAP_PROP_FRAME_WIDTH) / 2, cap.get(CAP_PROP_FRAME_HEIGHT) / 2);


	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "Video ended." << endl;
			break;
		}

		imshow(wName, frame);

		Mat contrastIncreaseBy4;
		frame.convertTo(contrastIncreaseBy4, -1, 4, 0);
		imshow(cx4, contrastIncreaseBy4);

		Mat contrastDecreasedBy0_5;
		frame.convertTo(contrastDecreasedBy0_5, -1, 0.5, 0);
		imshow(cx0_5, contrastDecreasedBy0_5);

		if (waitKey(10) == 27) {
			cout << "Esc key pressed. Stopping the video." << endl;
			break;
		}
	}

	return 0;
}