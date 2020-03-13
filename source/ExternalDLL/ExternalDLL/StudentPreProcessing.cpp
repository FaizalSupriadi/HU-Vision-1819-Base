#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &src) const {
	// Image container
	cv::Mat container;
	// Convert intensityimage to cv:mat
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, container);
	// Treshold is 220 and the max value is 255, overhill is input en output.

	//cv::threshold(container, container, 220, 255, cv::THRESH_BINARY_INV);
	
	//cv.adaptiveThreshold(container,container, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);
	
	// Adaptive treshold, de minimum wordt door de gaussian treshold bepaalt.
	//cv::adaptiveThreshold(container, container, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);
	
	// GaussianBlur is nodig voor de otsu treshold
	cv::GaussianBlur(container, container, cv::Size(5, 5), 0);
	// Otsu treshold determines the minimum value for the picture
	cv::threshold(container, container, 0, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU);
	
	// creates a new empty intensity image
	IntensityImage* intensity = ImageFactory::newIntensityImage();
	// Convert back to inensity image
	HereBeDragons::NoWantOfConscienceHoldItThatICall(container ,*intensity);
	return intensity;
}
