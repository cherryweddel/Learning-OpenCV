#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//注意，这个函数只能处理灰度图像，所以读取方式有所不同。
Mat image=imread("../lena.jpg",0);
int main()
{
    Mat result;

    //赋值参数，函数会将他赋给符合阈值条件的像素。
    double maxValue=255.0;

    //选择threshold方法
    AdaptiveThresholdTypes adaptiveMethod=ADAPTIVE_THRESH_MEAN_C;

    //阈值的类型必须是以下两种类型，THRESH_BINARY，正向二值化，THRESH_BINARY_INV ，反向二值化
    ThresholdTypes thresholdType=THRESH_BINARY;

    //此参数越大，自适应threshold方法所使用的像素就越多。
    int blockSize=11;

    //从平均数或加权平均数减去常量。通常，它是正的，但也可能是零或负数。
    double c=0.0;
    
    adaptiveThreshold(image,result,maxValue,adaptiveMethod,thresholdType,blockSize,c);

    namedWindow("Lena");
    namedWindow("Old");
    imshow("Old",image);
    imshow("Lena",result);

    waitKey(0);
    destroyWindow("Lena");
    destroyWindow("Old");
    return 0;   
}