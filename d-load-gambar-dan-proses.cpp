#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace cv;
using namespace std;
 
int main( )
{
    Mat src, qwe, asd, zxc, channel[3];
    
    String name = "file.jpg";
    src = imread( name, 1 );
    
    split(src,channel);

    channel[2].convertTo(qwe, CV_8UC3);
    channel[1].convertTo(asd, CV_8UC3);
    channel[0].convertTo(zxc, CV_8UC3); //urutan 0-1-2 bukan R-G-B, tapi B-G-R

    while(1){
 
    // Showing the result
    
    imshow( "yang diproses - R", qwe );
    imshow( "yang diproses - G", asd );
    imshow( "yang diproses - B", zxc );
    imshow( "source", src );

    cvWaitKey(50);
	}
}
