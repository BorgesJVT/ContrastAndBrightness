#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;

void contrast_thresh_trackbar(int, void *);
void brightness_thresh_trackbar(int, void *);

int alpha = 1;
int beta = 0;

int main() {
    Mat frame;
    Mat new_image;
    VideoCapture cap(0);
    namedWindow("Video Capture", WINDOW_NORMAL);
    namedWindow("Video Processed", WINDOW_NORMAL);

    //-- Trackbars to set thresholds for RGB values
    createTrackbar("Contrast","Video Processed", &alpha, 5, contrast_thresh_trackbar);
    createTrackbar("Brightness","Video Processed", &beta, 250, brightness_thresh_trackbar);

    while((char) waitKey(1) != 'q') {
        cap >> frame;
        if(frame.empty())
            break;
        
		new_image = Mat::zeros( frame.size(), frame.type() );
		for( int y = 0; y < frame.rows; y++ ) {
		    for( int x = 0; x < frame.cols; x++ ) {
		        for( int c = 0; c < 3; c++ ) {
		            new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( frame.at<Vec3b>(y,x)[c] ) + beta );
		        }
		    }
		}

        //-- Show the frames
        imshow("Video Capture", frame);
        imshow("Video Processed",new_image);
    }
    return 0;
}
void contrast_thresh_trackbar(int, void *) {

}
void brightness_thresh_trackbar(int, void *) {

}

