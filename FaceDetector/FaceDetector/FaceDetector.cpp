// FaceDetector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat image;
	image = imread("E:/work/git/FaceDetector/FaceDetector/x64/Debug/group1.jpg", IMREAD_COLOR);
	if (image.empty())
		return 0;

	cv::resize(image, image, cv::Size(500, 500));

	namedWindow("window1", 1);   
	imshow("window1", image);

	// Load Face cascade (.xml file)
	CascadeClassifier face_cascade;
	bool b = face_cascade.load("F:/Tools/Dev/openCV/opencv-4.0.0(build)/sources/data/haarcascades_cuda/haarcascade_frontalface_alt.xml");

	// Detect faces
	std::vector<Rect> faces;
	
	face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE);
	
	// Draw circles on the detected faces
	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
	}

	imshow("Detected Face", image);

	waitKey(0);

    return 0;
}

