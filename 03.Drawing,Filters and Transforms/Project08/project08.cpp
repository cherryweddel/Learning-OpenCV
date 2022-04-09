#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main()
{
    Mat image=imread("../lena.jpg");
    //显示要打印的文字
    string text = "Cherry is a  clever boy!";

    //确定文字显示的位置
    int offset=25;
    Point origin(offset,image.rows-offset);

    //确定字体
    HersheyFonts fontFace=FONT_HERSHEY_COMPLEX;

    // 尺寸因子，值越大文字越大
    double fontScale=1;

    //确定文字颜色
    Scalar color(255,255,255);

    //设置文字粗细，值越大文字越粗
    int thickness=2;

    //确定线条类型
    LineTypes lineType = LINE_AA;

    //文字是否倒转
    bool bottomLeftOrigin=true;

    //放置文字
    putText(image,
                    text,
                    origin,
                    fontFace,
                    fontScale,
                    color,
                    thickness,
                    lineType,
                    bottomLeftOrigin);
    //显示图片
    namedWindow("Lena");
    imshow("Lena",image);

    waitKey(0);

    destroyWindow("Lena");
    return 0;   
}