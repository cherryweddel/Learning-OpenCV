#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

Mat img;

//我们应用三种类型的滤镜：模糊、Sobel过滤器以及将颜色转化为灰色，并将过滤器状态都设置为否
/*bool applyGray=false;
bool applyBlur=false;
bool applySobel=false;

void applyFilters(){
    Mat result;
    img.copyTo(result);
    if(applyGray){
        cvtColor(result,result,COLOR_BGR2GRAY);
    }
    if(applyBlur){
        blur(result,result,Size(5,5));
    }
    if(applySobel){
        Sobel(result,result,CV_8U,1,1);
    }
    imshow("Lena",result);
}

void grayCallback(int state,void* userData)
{
    applyGray=true;
    applyFilters();
}

void bgrCallback(int state,void* userData)
{
    applyGray=false;
    applyFilters();
}

void blurCallback(int state,void* userData)
{
    applyBlur=(bool)state;
    applyFilters();
}

void sobelCallback(int state,void* userData)
{
    applySobel=!applySobel;
    applyFilters();
}*/



int main()
{
    img=imread("../lena.jpg");
    namedWindow("Lena");
    namedWindow("Gray");
    namedWindow("Sobel");
    namedWindow("Blur");
    Mat gray;
    Mat sobel;
    Mat blu;

    img.copyTo(gray);
    img.copyTo(sobel);
    img.copyTo(blu);

    cvtColor(gray,gray,COLOR_BGR2GRAY);
    Sobel(sobel,sobel,CV_8U,1,1);
    blur(blu,blu,Size(5,5));

    imshow("Lena",img);
    imshow("Gray",gray);
    imshow("Sobel",sobel);
    imshow("Blur",blu);

    waitKey(0);

    destroyWindow("Lena");
    return 0;    
}