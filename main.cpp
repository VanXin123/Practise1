//Practice 1.
//Aims: A first program using OpenCV; familiar with operations on images.

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
int main() {
	cv::Mat imOrig;		//create a variable to hold image
//	if (!imOrig.data) { std::cout << "No Image Data Yet... "; }    // no image has been created…
//	std::cout << " Size: " << imOrig.size().height << " , " << imOrig.size().width << std::endl;	//gives size of the array "image"
	
	//Read the information of original image
	imOrig = cv::imread("lena.bmp");	//read an image
	if (!imOrig.data) { cout << "No Image Data Yet... "; }    // no image has been created… 
	cout << "Size: " << imOrig.size().height << " , " << imOrig.size().width << endl;	//gives size of the array "image"

	//Choose which Image Processing do you want?
	int response = 0;  //define the response of users
	cout << "Please choose a image processing method!" << endl;  //Guide users to choose a method to process image
	cout << "1. Fip" << endl;  //Flip image
	cout << "2. Canny" << endl;  //Canny image
	cout << "3. Resize" << endl;  //Resize image
	cout << "4. GaussinBlur" << endl;  //GaussianBlur image
	cout << "Make your choice: ";  //It's time to let users make a choice!
	cin >> response;  //input users's choice

	//Flip
	if (response == 1)
	{
		//cv::cvtColor(imOrig, imOrig, 6); //Convert to Gray Scale
		cv::Mat imFlip;	//Image with some modifications
		//Flip an Image
		cv::flip(imOrig, imFlip, -1); //Flips an Image
		//Display Images
		cv::namedWindow("Original Image");	//create window for image named as "Original Image"
		cv::namedWindow("Flipped Image");	//create window for image named as "Flipped Image"
		cv::imshow("Original Image", imOrig);	//show image in that window
		cv::imshow("Flipped Image", imFlip);	//show image in that window
		cv::waitKey();	//wait for 5000 ms = 5 sec
		cv::imwrite("lenaFlip.bmp", imFlip);	//Save imFilp 
	}
	
	//Canny
	if (response == 2)
	{
		//cv::cvtColor(imOrig, imOrig, 6); //Convert to Gray Scale
		cv::Mat imCanny;	//Image with some modifications
		//Canny an Image
		double threshold1 = 10;  //define Threshold 1
		double threshold2 = 200;  //define Threshold 2
		int apertureSize = 3;  //Sober operator size
		bool L2gradient = false;  //Whether to use a more accurate way of calculating image gradients
		cv::Canny(imOrig, imCanny, threshold1, threshold2, apertureSize, L2gradient);   //Canny an Image
		//Display Images
		cv::namedWindow("Original Image");	//create window for image named as "Original Image"
		cv::namedWindow("Canny Image");	//create window for image named as "Canny Image"
		cv::imshow("Original Image", imOrig);	//show image in that window
		cv::imshow("Canny Image", imCanny);	//show image in that window
		cv::waitKey();	//wait for 5000 ms = 5 sec
		cv::imwrite("lenaCanny.bmp", imCanny);	//Save imCanny 
	}
	//Resize
	if (response == 3)
	{
		//cv::cvtColor(imOrig, imOrig, 6); //Convert to Gray Scale
		cv::Mat imResize;	//Image with some modifications
		//Resize an Image
		cv::Size dsize(0, 0);  //The output image size will be the same as dsize, when dsize is equal to 0, 
							   //the output image size will be calculated from the input image size, fx, fy
		double fx = 0.5;  //Horizontal scaling
		double fy = 0.5;  //Vertical scaling
						  //if fx and fy = 0, dsize must not be 0. dsize can be considered as Horizontal scaling and Vertical scaling.
		int interpolation = cv::INTER_LINEAR;  //bilinear interpolation, A good balance of image quality and time spent
											   //INTER_NEAREST: nearest neighbor interpolation
											   //INTER_AREA: resampling using pixel area relatio, When we shrink the image, we get better results
											   //INTER_CUBIC: bicubic interpolation, We enlarge the image，can get the best results, but the calculation takes more time
											   //INTER_LANCZOS4: Lanczos interpolation over 8x8 neighborhood
		cv::resize(imOrig,imResize,dsize,  fx,  fy ,interpolation); //Resize an Image
		//Display Images
		cv::namedWindow("Original Image");	//create window for image named as "Original Image"
		cv::namedWindow("Resize Image");	//create window for image named as "Resize Image"
		cv::imshow("Original Image", imOrig);	//show image in that window
		cv::imshow("Resize Image", imResize);	//show image in that window
		cv::waitKey();	//wait for 5000 ms = 5 sec
		cv::imwrite("lenaResize.bmp", imResize);	//Save imResize 
	}
	//GaussianBlur
	if (response == 4)
	{
		//cv::cvtColor(imOrig, imOrig, 6); //Convert to Gray Scale
		cv::Mat imGaussianBlur;	//Image with some modifications
		//GaussianBlur an Image
		cv::Size ksize(5, 5);		//Gaussian kernel size. ksize.width and ksize.height can differ 
									//but they both must be positive and odd.
									//Or, they can be zero's and then they are computed from sigma.
		//We can find that The larger the kernel size, the more blurred the image!!!!!!
		double sigmaX = 3;  //Gaussian kernel standard deviation in X direction.
		double sigmaY = 3;  //(standard deviation of the Gaussian kernel in the y - direction
							//(for sigmaY = 0, their values are automatically determined by sigmaX(sigmaY = sigmaX); 
							//for sigmaY = sigmaX = 0, their values will be automatically determined by ksize.width and ksize.height))
		cv::GaussianBlur(imOrig, imGaussianBlur, ksize, sigmaX, sigmaY); //GaussianBlur an Image
		//Display Images
		cv::namedWindow("Original Image");	//create window for image named as "Original Image"
		cv::namedWindow("GaussianBlur Image");	//create window for image named as "GaussianBlur Image"
		cv::imshow("Original Image", imOrig);	//show image in that window
		cv::imshow("GaussianBlur Image", imGaussianBlur);	//show image in that window
		cv::waitKey();	//wait for 5000 ms = 5 sec
		cv::imwrite("lenaGaussianBlur.bmp", imGaussianBlur);	//Save imGaussianBlur 
	}

	return 1;

}