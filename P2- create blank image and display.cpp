#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	// generate an image with 800 x 600 (width x height) === ( cols x rows )
	
	Mat image(600, 800, CV_8UC3, Scalar(100, 200, 50));
	//       ^rows ^cols
	
	String windowName = "Blank image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}