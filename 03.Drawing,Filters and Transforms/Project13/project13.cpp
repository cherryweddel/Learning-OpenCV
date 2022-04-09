//本PROJECT是几个滤镜的综合运用，同时运用了从摄像头捕获的技术
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
//imgproc.hpp包含相关头文件
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

int main()
{
	//读取视频或摄像头
	VideoCapture capture(0);
	
    //永真循环，即摄像头一直保持打开
	while (true)
	{
		Mat frame;
		capture >> frame;
        //将capture捕获的图像写入frame中。
        MorphTypes op=MORPH_ERODE;
        MorphShapes shape=MORPH_RECT;
        Point anchor(-1,-1);
        Size ksize(3,3);
        Mat kernel=getStructuringElement(shape,ksize,anchor);
        int iterations=3;
        BorderTypes borderType=BORDER_CONSTANT;
        Scalar borderValue=morphologyDefaultBorderValue();
        Mat result;
        Mat sobel;
        morphologyEx(frame,
                                result,
                                op,
                                kernel,
                                anchor,
                                iterations,
                                borderType,
                                borderValue);
        Sobel(frame,sobel,CV_8U,1,1);
		imshow("读取视频", result);
        imshow("原相机",frame);
        imshow("索伯算子",sobel);
		if (waitKey(1) == 27)//按ESC键
            {
                cout << "程序结束！" << endl;
                cout << "*** ***" << endl;
                //break时，循环结束，窗口关闭。
				break;
            }
	}
	return 0;
}