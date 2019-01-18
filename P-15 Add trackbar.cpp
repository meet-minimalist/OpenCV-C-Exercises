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
	
	int iBrightness = 50;
	createTrackbar("Brightness", window, &iBrightness, 100);

	int iContrast = 50;
	createTrackbar("Contrast", window, &iContrast, 100);

	while (true) {
		Mat dst;
		int iBrightness_value = iBrightness - 50;
		double iContrast_value = iContrast / 50.0;

		image.convertTo(dst, -1, iContrast_value, iBrightness_value);
		imshow(window, dst);

		if (waitKey(10) == 27) {
			break;
		}
	}
	
	
	waitKey(0);
	destroyAllWindows();

	return 0;
}