 添加opencv库包含
 添加以下信息
 CONFIG += console c++11
 CONFIG -= app_bundle
 CONFIG -= qt
#打开.pro文件，在文件末尾添加如下语句：

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2
LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so

Step3. 添加测试程序
打开main.cpp文件，将其修改为：

#include "mainwindow.h"
#include <QApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    // opencv test
    namedWindow("src");
    Mat src = imread("/usr/local/opencv-2.4.10/samples/cpp/lena.jpg");
    imshow("src",src);
    waitKey();
    return 0;

    //return a.exec();
}
