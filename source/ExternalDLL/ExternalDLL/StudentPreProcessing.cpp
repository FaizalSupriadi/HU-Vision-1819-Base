#include "StudentPreProcessing.h"
#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include <iostream>
#include <math.h>
#include <array>
#include <chrono>

using namespace std::chrono;

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &src) const {
	
	IntensityImage* edgeDetectionImage = ImageFactory::newIntensityImage();
	microseconds totalDuration = milliseconds(0);

	for (int i = 0; i < 1000; i++) {
		auto start = high_resolution_clock::now();

		cv::Mat imageContainer;
		HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, imageContainer);

		cv::Mat prewittx = (cv::Mat_<float>(3, 3) << 1, 0, -1, 1, 0, -1, 1, 0, -1);
		cv::Mat prewitty = (cv::Mat_<float>(3, 3) << 1, 1, 1, 0, 0, 0, -1, -1, -1);

		cv::Mat prewittxResult;
		cv::Mat prewittyResult;


		filter2D(imageContainer, prewittxResult, -1, prewittx, cv::Point(-1, -1));
		filter2D(imageContainer, prewittyResult, -1, prewitty, cv::Point(-1, -1));

		cv::Mat weighted;
		cv::addWeighted(prewittxResult, 3, prewittyResult, 3, 0, weighted, -1);

		HereBeDragons::NoWantOfConscienceHoldItThatICall(weighted, *edgeDetectionImage);

		auto stop = high_resolution_clock::now();
		totalDuration += duration_cast<microseconds>(stop - start);
	}
	std::cout << "-----------------------------" << totalDuration.count() / 1000 << std::endl;
	
	return edgeDetectionImage;

	
	
	IntensityImage* edgeDetectionImage = ImageFactory::newIntensityImage();
	microseconds totalDuration = milliseconds(0);

	for (int i = 0; i < 1000; i++) {
		auto start = high_resolution_clock::now();

		cv::Mat imageContainer;

		HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, imageContainer);

		cv::Mat sobelx = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
		cv::Mat sobely = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

		cv::Mat sobelxResult;
		cv::Mat sobelyResult;

		filter2D(imageContainer, sobelxResult, -1, sobelx, cv::Point(-1, -1));
		filter2D(imageContainer, sobelyResult, -1, sobely, cv::Point(-1, -1));

		IntensityImage* edgeDetectionImage = ImageFactory::newIntensityImage();

		cv::Mat weighted;
		cv::addWeighted(sobelxResult, 3, sobelyResult, 3, 0, weighted, -1);

		HereBeDragons::NoWantOfConscienceHoldItThatICall(weighted, *edgeDetectionImage);

		auto stop = high_resolution_clock::now();
		totalDuration += duration_cast<microseconds>(stop - start);
	}
	std::cout << "-----------------------------" << totalDuration.count() << std::endl;

	return edgeDetectionImage;
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
	cv::threshold(container, container, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
	// creates a new empty intensity image
	IntensityImage* intensity = ImageFactory::newIntensityImage();
	// Maak er weer een rij van en stop het in thorough
	// Convert back
	HereBeDragons::NoWantOfConscienceHoldItThatICall(container, *intensity);
	return intensity;
}

