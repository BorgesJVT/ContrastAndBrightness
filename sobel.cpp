#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat sobel;
    namedWindow("Video Capture",1);
    namedWindow("Sobel Filter",1);
    while((char) waitKey(1) != 'q') {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, sobel, COLOR_BGR2GRAY);
//cout << "mark1" << endl;
        Sobel(sobel, sobel, CV_8U, 1, 1);
		bitwise_not ( sobel, sobel );

//cout << "mark2" << endl;
        imshow("Video Capture", frame);
        imshow("Sobel Filter", sobel);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
