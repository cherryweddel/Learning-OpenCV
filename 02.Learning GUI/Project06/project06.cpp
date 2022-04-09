#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"
using namespace cv;

int blurAmount=15;

static void onChange(int pos,void* userInput);

static void onMouse(int event,int x,int y,int,void* userInput);

int main(int argc,const char** argv)
{
    Mat lena=imread("../lena.jpg");

    namedWindow("Lena");

    createTrackbar("Lena","Lena",&blurAmount,30,onChange,&lena);
    setMouseCallback("Lena",onMouse,&lena);

    onChange(blurAmount,&lena);

    waitKey(0);

    destroyWindow("Lena");

    return 0;

}

static void onChange(int pos, void* userInput)
{
	if(pos <= 0)
		return;
	// Aux variable for result
	Mat imgBlur;

	// Get the pointer input image
	Mat* img= (Mat*)userInput;

	// Apply a blur filter
	blur(*img, imgBlur, Size(pos, pos));	

	// Show the result
	imshow("Lena", imgBlur);
}

//Mouse callback
static void onMouse( int event, int x, int y, int, void* userInput )
{
	if( event != EVENT_LBUTTONDOWN )
	        return;

	// Get the pointer input image
	Mat* img= (Mat*)userInput;
	
	// Draw circle
	circle(*img, Point(x, y), 10, Scalar(0,255,0), 3);

	// Call on change to get blurred image
	onChange(blurAmount, img);

}
