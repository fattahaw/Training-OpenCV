#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace cv;
using namespace std;
 
int main( )
{
 //   Mat src, qwe, asd, zxc, channel[3];
    
    String source = "file.jpg";
    src = imread( source, 1 );
    
//   split(src,channel);

//    channel[2].convertTo(qwe, CV_8UC3);
//    channel[1].convertTo(asd, CV_8UC3);
//    channel[0].convertTo(zxc, CV_8UC3); //urutan 0-1-2 bukan R-G-B, tapi B-G-R
    
    int iLowH = 67;
	int iHighH = 78;
	
	int iLowS = 112; 
	int iHighS = 187;
	
	int iLowV = 0;
	int iHighV = 255;

	namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

	//Create trackbars in "Control" window
	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 179);
	
	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);
	
	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);
 

    while(1){
		
	Mat imgHSV;
	cvtColor(src, imgHSV, CV_BGR2HSV); //Convert the captured frame from BGR to HSV
 
	Mat imgThresholded;

	inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
 
    // Showing the result
    
//    imshow( "yang diproses - G", asd );
    imshow( "thresholded", imgThresholded );
    imshow( "source", src );

    cvWaitKey(50);
	}
}
