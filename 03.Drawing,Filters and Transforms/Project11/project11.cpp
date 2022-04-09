#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//分别对应窗口名称和轨迹条名称
string window="Image";
string trackbar="Radius";

Mat image=imread("../Test.png");

//圆心的位置、初始半径
Point center(image.cols/2,image.rows/2);
int radius=25;

//颜色
Scalar color=Scalar(0,255,0);

//规定线条
int thickness=2;LineTypes lineType=LINE_AA;int shift=0;

//回调函数，当轨迹条更改所绘制圆形的半径时，他将会被回调。
//此函数必须具有本例中使用的签名，签名的参数为int型和void指针类型
//这个函数非常简单，仅克隆原始图像，并在上面绘制一个圆形，然后显示出来。
void drawCircle(int,void*)
{
    Mat temp=image.clone();
    circle(temp,
                center,
                radius,
                color,
                thickness,
                lineType,
                shift);
    imshow(window,temp);
}

int main()
{
    namedWindow(window);

    //创建轨迹条，下面我们会就其中的参数进行解析。
    createTrackbar(trackbar,window,&radius,min(image.rows,image.cols)/2,drawCircle);

    //确保轨迹条可调整半径不小于25且不大于图像的宽度或长度值的一半。
    setTrackbarMin(trackbar,window,25);
    setTrackbarMax(trackbar,window,min(image.rows,image.cols)/2);

    //画出初始的圆。
    drawCircle(0,0);

    waitKey();

    return 0;
}