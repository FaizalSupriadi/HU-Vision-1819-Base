#include "StudentPreProcessing.h"
#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &src) const {
	// Image container
	cv::Mat image;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, image);

	cv::Mat prewittx = (cv::Mat_<float>(3, 3) << 1, 0, -1, 1, 0, -1, 1, 0, -1 );
	cv::Mat prewitty = (cv::Mat_<float>(3, 3) << 1, 1, 1, 0, 0, 0, -1, -1, -1 );
	// Image container als output
	cv::Mat prewittxResult;
	cv::Mat prewittyResult;
	// Convuleer de afbeelding met de kernel, overhill is input, overpark is output
	filter2D(image, prewittxResult, CV_8U, prewittx, cv::Point(-1, -1));
	filter2D(image, prewittyResult, CV_8U, prewitty, cv::Point(-1, -1));
	// creates a new empty intensity image
	IntensityImage* endResult = ImageFactory::newIntensityImage();
	// Maak er weer een rij van en stop het in thorough
	HereBeDragons::NoWantOfConscienceHoldItThatICall(prewittxResult + prewittyResult, *endResult);
	return endResult;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}
