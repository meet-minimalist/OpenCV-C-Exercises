#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C:\\Users\\Meet\\Desktop\\OpenCV + C++\\Best pic_opencv.jpg");
	
	if (image.empty()) {
		cout << "Error in reading image file." << endl;
		cin.get();
		return -1;
	}

	String original = "Original Image";
	namedWindow(original, WINDOW_NORMAL);
	resizeWindow(original, image.cols / 4, image.rows / 4);
	imshow(original, image);


	Mat hist_equalized_image;
	// We cant directly apply histogram equalization on RGB channel as they are correlated. Their intensities and color values are correlated.
	// You couldn't just apply this to RGB because changing RGB ratios would result in weird colour changes. 
	// So after converting it to YCrCB, you only change the contrast of the intensity information and then re-convert it back to RGB.
	// Because in YCrCb, the Y channel is responsible for intensities and other two channels contain color information.

	cvtColor(image, hist_equalized_image, COLOR_BGR2YCrCb);

	// vector is just like an array with size adapted as per the elements added or removed
	vector<Mat> vec_channels;
	split(hist_equalized_image, vec_channels);			// split all three channels separately : Y channel, Cr channel, Cb channel
	equalizeHist(vec_channels[0], vec_channels[0]);		// we equalize only Y channel which contains only intensities.
	merge(vec_channels, hist_equalized_image);

	cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);

	String histWindow = "Histogram Equalized Image";
	namedWindow(histWindow, WINDOW_NORMAL);
	resizeWindow(histWindow, hist_equalized_image.cols / 4, hist_equalized_image.rows / 4);
	imshow(histWindow, hist_equalized_image);

	waitKey(0);
	destroyAllWindows();

	return 0;
}