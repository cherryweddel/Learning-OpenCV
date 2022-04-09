#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat image=imread("../lena.jpg");
int main()
{
    //指定形态操作方式，这里使用腐蚀操作
    MorphTypes op=MORPH_DILATE;

    //规定变形形状
    MorphShapes shape=MORPH_RECT;

    //规定核大小
    Size ksize(3,3);

    //规定锚点
    Point anchor(-1,-1);

    //创建核矩阵
    Mat kernel=getStructuringElement(shape,ksize,anchor);

    //规定执行操作的次数
    int iterations=10;

    //扩充边缘扩充边缘
    BorderTypes borderType=BORDER_CONSTANT;
    Scalar borderValue=morphologyDefaultBorderValue();
    Mat result;
    morphologyEx(image,
                                result,
                                op,
                                kernel,
                                anchor,
                                iterations,
                                borderType,
                                borderValue);
    namedWindow("Lena");
    namedWindow("Old");
    imshow("Old",image);
    imshow("Lena",result);

    if (waitKey(9000)==27)
        {destroyWindow("Lena");
        destroyWindow("Old");}
    return 0;   
}