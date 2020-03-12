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
	cv::Mat OverHillOverDale;
	//HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, OverHillOverDale);

	int w = src.getWidth();
	int h = src.getHeight();

	OverHillOverDale.create(h, w, CV_8UC1);

	for (int x = 0; x < OverHillOverDale.cols; x++) {
		for (int y = 0; y < OverHillOverDale.rows; y++) {
			OverHillOverDale.at<uchar>(y, x) = src.getPixel(x, y);
		}
	}

	cv::Mat prewittx = (cv::Mat_<float>(3, 3) << 1, 0, -1, 1, 0, -1, 1, 0, -1 );
	cv::Mat prewitty = (cv::Mat_<float>(3, 3) << 1, 1, 1, 0, 0, 0, -1, -1, -1 );
	// Image container als output
	cv::Mat prewittxResult;
	cv::Mat prewittyResult;
	// Convuleer de afbeelding met de kernel, overhill is input, overpark is output
	filter2D(OverHillOverDale, prewittxResult, CV_8U, prewittx, cv::Point(-1, -1));
	filter2D(OverHillOverDale, prewittyResult, CV_8U, prewitty, cv::Point(-1, -1));
	// creates a new empty intensity image
	IntensityImage* ThoroughFloodThoroughFire = ImageFactory::newIntensityImage();
	// Maak er weer een rij van en stop het in thorough
	HereBeDragons::NoWantOfConscienceHoldItThatICall(prewittxResult + prewittyResult, *ThoroughFloodThoroughFire);
	return ThoroughFloodThoroughFire;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}