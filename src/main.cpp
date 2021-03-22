#include <stdio.h>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "CannyLine.h"

using namespace cv;
using namespace std;


int main()
{	
	string fileCur("../image/ecc200_contrast_variations_01.png");
	cv::Mat img = imread( fileCur, 0 );
	if(img.empty()) return -1;

	CannyLine detector;
	std::vector<std::vector<float> > lines;
	lines = CannyLine::cannyLine(img);

	// show
	cv::Mat imgShow( img.rows, img.cols, CV_8UC3, cv::Scalar( 255, 255, 255 ) );
	for (auto & m : lines)
	{

		cv::line( imgShow, cv::Point( m[0], m[1] ), cv::Point( m[2], m[3] ), cv::Scalar(0,0,0), 1);
	}
	cv::imwrite(fileCur+".canny.png", imgShow);

	return 0;
}