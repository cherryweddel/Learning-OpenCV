#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat image=imread("../lena.jpg");
int main()
{
    Mat result;

    //为了更清晰的显示结果，我们先把图片转化为灰度图
    cvtColor(image,image,COLOR_BGR2GRAY);

    //最小的阈值
    double thresh=200.0;

    //最大值
    double maxval=255.0;
    //简单来说，在thresh以及maxal之间的所有像素值都会被选中，由此得到结果

    //规定阈值类型
    ThresholdTypes type=THRESH_BINARY;

    threshold(image,
                        result,
                        thresh,
                        maxval,
                        type);
    namedWindow("Lena");
    namedWindow("Old");
    imshow("Old",image);
    imshow("Lena",result);

    waitKey(0);
    destroyWindow("Lena");
    destroyWindow("Old");
    return 0;   
}