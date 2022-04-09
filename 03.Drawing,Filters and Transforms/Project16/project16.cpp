#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//注意，这个函数只能处理灰度图像，所以读取方式有所不同。
Mat image=imread("../lena.jpg");
int main()
{
    Mat result;

    Mat mapX(image.size(),CV_32FC1);
    Mat mapY(image.size(),CV_32FC1);

    Point2f center(image.cols/2,image.rows/2);

    for (int i=0;i<image.rows;i++)
    {
        for (int j=0;j<image.cols;j++)
        {
            double x=j-center.x;
            double y=i-center.y;

            x=x*x/750;
            y=y;

            mapX.at<float>(i,j)=x+center.x;
            mapY.at<float>(i,j)=y+center.y;
        }
    }

    InterpolationFlags interpolation=INTER_CUBIC;
    BorderTypes borderMode = BORDER_CONSTANT;
    Scalar borderValue=Scalar(0,0,0);
    remap(image,
                result,
                mapX,
                mapY,
                interpolation,
                borderMode,
                borderValue);

    imwrite("../result.jpg",result);

    namedWindow("Lena");
    namedWindow("Old");
    imshow("Old",image);
    imshow("Lena",result);

    waitKey(0);
    destroyWindow("Lena");
    destroyWindow("Old");
    return 0;   
}