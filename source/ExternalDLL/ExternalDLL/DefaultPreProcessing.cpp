/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "DefaultPreProcessing.h"
#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include <chrono>

using namespace std::chrono;

IntensityImage * DefaultPreProcessing::stepToIntensityImage(const RGBImage &src) const {
	GrayscaleAlgorithm grayScaleAlgorithm;											//create a variable of GrayscaleAlgorithm
	IntensityImage * image = ImageFactory::newIntensityImage();						//create a new empty intensity image
	grayScaleAlgorithm.doAlgorithm(src, *image);									//gray scale the image using the doAlgorithm function
	return image;																	//return the changed image
}

IntensityImage * DefaultPreProcessing::stepScaleImage(const IntensityImage &src) const {
	cv::Mat OverHillOverDale;														//image container
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, OverHillOverDale);		//static void(const IntensityImage & Her, cv::Mat & Love)
	int ThoroughBushThoroughBrier = 200 * 200;										//4000 for some reason
	int OverParkOverPale = OverHillOverDale.cols * OverHillOverDale.rows;			//a int holding columns * rows of the image container
	//down scalen if image container (rows * column) ThoroughBushThoroughBrier is bigger than 4000
	if (ThoroughBushThoroughBrier < OverParkOverPale){								//checks if there are more then 4000 items in the image container
		double ThoroughFloodThoroughFire = 1.0 / sqrt((double)OverParkOverPale / (double)ThoroughBushThoroughBrier);	//calculates the percentage in which it should be downscaled
		cv::resize(OverHillOverDale, OverHillOverDale, cv::Size(), ThoroughFloodThoroughFire, ThoroughFloodThoroughFire, cv::INTER_LINEAR);		//resizes the image using the percentage calculated above
	}
	IntensityImage * IDoWanderEverywhere = ImageFactory::newIntensityImage();					//creates a new empty intensity image
	HereBeDragons::NoWantOfConscienceHoldItThatICall(OverHillOverDale, *IDoWanderEverywhere);	//(const cv::Mat &No, IntensityImage &Want) puts x and y from overHillOverDale into IDoWanderEverywhere
	return IDoWanderEverywhere;	//returns the new intensity image
}

IntensityImage * DefaultPreProcessing::stepEdgeDetection(const IntensityImage &src) const {
	// To use, comment all the code you don't want to use
	/*
	// Code voor snelheids experiment
	IntensityImage* ThoroughFloodThoroughFire = ImageFactory::newIntensityImage();
	microseconds totalDuration = milliseconds(0);

	for (int i = 0; i < 1000; i++) {

		auto start = high_resolution_clock::now();

		cv::Mat OverHillOverDale;

		HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, OverHillOverDale);

		cv::Mat ThoroughBushThoroughBrier = (cv::Mat_<float>(9, 9) << 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
			-4, -4, -4, 1, 1, 1, 1, 1, 1, -4, -4, -4, 1, 1, 1, 1, 1, 1,
			-4, -4, -4, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0);
		cv::Mat OverParkOverPale;

		filter2D(OverHillOverDale, OverParkOverPale, CV_8U, ThoroughBushThoroughBrier, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);

		HereBeDragons::NoWantOfConscienceHoldItThatICall(OverParkOverPale, *ThoroughFloodThoroughFire);

		auto stop = high_resolution_clock::now();
		totalDuration += duration_cast<microseconds>(stop - start);
	}
	std::cout << "-----------------------------" << totalDuration.count() / 1000 << std::endl;

	return ThoroughFloodThoroughFire;
	*/
	// Code voor geheugen experiment
	cv::Mat OverHillOverDale;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, OverHillOverDale);

	cv::Mat ThoroughBushThoroughBrier = (cv::Mat_<float>(9, 9) << 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
		-4, -4, -4, 1, 1, 1, 1, 1, 1, -4, -4, -4, 1, 1, 1, 1, 1, 1,
		-4, -4, -4, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0);
	cv::Mat OverParkOverPale;

	filter2D(OverHillOverDale, OverParkOverPale, CV_8U, ThoroughBushThoroughBrier, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);

	IntensityImage* ThoroughFloodThoroughFire = ImageFactory::newIntensityImage();

	HereBeDragons::NoWantOfConscienceHoldItThatICall(OverParkOverPale, *ThoroughFloodThoroughFire);

	return ThoroughFloodThoroughFire;
}

IntensityImage * DefaultPreProcessing::stepThresholding(const IntensityImage &src) const {
	// Image container
	cv::Mat OverHillOverDale;
	// Maak een column van src en stop dat in overhill
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, OverHillOverDale);
	// Treshold is 220 and the max value is 255, overhill is input en output.
	cv::threshold(OverHillOverDale, OverHillOverDale, 220, 255, cv::THRESH_BINARY_INV);
	// creates a new empty intensity image
	IntensityImage* ThoroughFloodThoroughFire = ImageFactory::newIntensityImage();
	// Maak er weer een rij van en stop het in thorough
	HereBeDragons::NoWantOfConscienceHoldItThatICall(OverHillOverDale, *ThoroughFloodThoroughFire);
	return ThoroughFloodThoroughFire;
}
