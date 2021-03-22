#include "CannyLine.h"
#include "MetaLine.h"

CannyLine::CannyLine(void)
= default;

CannyLine::~CannyLine(void)
= default;

std::vector<std::vector<float>> CannyLine::cannyLine(cv::Mat &image)
{
	MetaLine deterctor;
	float gausSigma=1.0;
	int gausHalfSize=1;
    std::vector<std::vector<float>> lines;
	lines = deterctor.MetaLineDetection(image,gausSigma,gausHalfSize);
    return lines;
}