#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

void windowsize_trackbar(int, void *);
int windowsize = 3;

int main() {
    Mat frame, frame_gray;
    VideoCapture cap(0);
    namedWindow("Video Capture", WINDOW_NORMAL);
    namedWindow("Video Processed", WINDOW_NORMAL);
    createTrackbar("Window Size","Video Processed", &windowsize, 50, windowsize_trackbar);

    while((char)waitKey(1) != 'q') {
        cap >> frame;

        if(frame.empty())
            break;

		cvtColor(frame, frame_gray, CV_BGR2GRAY);
		blur(frame_gray, frame_gray, Size(windowsize, windowsize));
		
        //-- Show the frames
        imshow("Video Capture", frame);
        imshow("Video Processed", frame_gray);
    }
    return 0;
}
void windowsize_trackbar(int, void *) {
    if(windowsize == 0) windowsize = 1;
}
