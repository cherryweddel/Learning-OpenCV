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

    //确定起点终点的两个点的位置
    Point pt1(25,image.rows/2);
    Point pt2(image.cols/2-25,image.rows/2);

    //规定线条的颜色
    Scalar color=Scalar(0,255,0);

    //规定线条的粗细
    int thickness=1;

    //规定线条类型
    int lineType=LINE_AA;

    //对应给定点上的小数位数，你可以省略或简单地传递0确保它对你的结果没有影响
    int shift=0;

    //绘制线条
    line(image,
            pt1,
            pt2,
            color,
            thickness,
            lineType,
            shift);

    //显示图片
    namedWindow("Lena");
    imshow("Lena",image);

    waitKey(0);

    destroyWindow("Lena");
    return 0;   
}