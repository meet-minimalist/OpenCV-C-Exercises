#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);

	if(cap.isOpened() == false){
		cout << "Can't open video camera." << endl;
		cin.get();
		return -1;
	}

	int w = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

	Size frameSize(w, h);
	int frames_per_sec = 5;
	// increas record fps to 30 to record in fast motion or to record in slow motion change it to 5

	VideoWriter oVideoWriter("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\captured_video.mp4", VideoWriter::fourcc('M', 'J', 'P', 'G'),
		frames_per_sec, frameSize, true);

	if (oVideoWriter.isOpened() == false) {
		cout << "Can not save video to the file." << endl;
		cin.get();
		return -1;
	}

	String wName = "Webcam stream";
	namedWindow(wName);

	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "Video camera disconnected." << endl;
			cin.get();
			break;
		}

		oVideoWriter.write(frame);
		imshow(wName, frame);

		if (waitKey(10) == 27) {
			cout << "Esc key is pressed by user. Stopping the web cam stream." << endl;
			break;
		}
	}

	oVideoWriter.release();
	return 0;
}