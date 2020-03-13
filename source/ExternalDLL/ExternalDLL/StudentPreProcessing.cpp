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

	cv::Mat prewittx = (cv::Mat_<float>(3, 3) << 1, 0, -1, 1, 0, -1, 1, 0, -1);
	cv::Mat prewitty = (cv::Mat_<float>(3, 3) << 1, 1, 1, 0, 0, 0, -1, -1, -1);
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

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &src) const {
	// Image container
	cv::Mat container;
	// Maak een column van src en stop dat in overhill
	// Convert intensityimage to cv:mat
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, container);
	// Treshold is 220 and the max value is 255, overhill is input en output.

	//cv::threshold(container, container, 220, 255, cv::THRESH_BINARY_INV);
	//cv.adaptiveThreshold(container,container, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);
	// Adaptive treshold, de minimum wordt door de gaussian treshold bepaalt.
    //cv::adaptiveThreshold(container, container, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 15, 10);
	cv::GaussianBlur(container, container, cv::Size(5, 5), 0);
	cv::threshold(container, container, 0, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU);
	// creates a new empty intensity image
	IntensityImage* intensity = ImageFactory::newIntensityImage();
	// Maak er weer een rij van en stop het in thorough
	// Convert back
	HereBeDragons::NoWantOfConscienceHoldItThatICall(container ,*intensity);
	return intensity;
}
