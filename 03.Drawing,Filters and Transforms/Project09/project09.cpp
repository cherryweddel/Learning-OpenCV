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

    //规定标记的位置
    Point position(image.cols/2,image.rows/2);

    //规定标记颜色
    Scalar color =Scalar::all(255);

    //规定标记种类
    MarkerTypes markerType=MARKER_TILTED_CROSS;

    //规定标记大小
    int markerSize=10;

    //规定线条粗细
    int thickness=2;

    //规定线条类型
    int lineType=LINE_AA;

    //画出标记
    drawMarker(image,
                            position,
                            color,
                            markerType,
                            markerSize,
                            thickness,
                            lineType);
    //显示图片
    namedWindow("Lena");
    imshow("Lena",image);

    waitKey(0);

    destroyWindow("Lena");
    return 0;   

}