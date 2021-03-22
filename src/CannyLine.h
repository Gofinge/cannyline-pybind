#ifndef _CANNY_LINE_H_
#define _CANNY_LINE_H_
#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

class CannyLine
{
public:
	CannyLine();
	~CannyLine();

	static std::vector<std::vector<float>> cannyLine(cv::Mat &image);
};

#endif // _CANNY_LINE_H_

