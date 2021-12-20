/*-----------CreateNoise类-------------------*/
//CreateNoise.h文件
//功能：产生图像噪声
//使用：调用成员函数void AddGaussianNoise(Mat&)添加高斯噪声
//调用成员函数void AddPepperNoise(Mat&int n)添加高斯噪声
//调用成员函数void AddSaitNoise(Mat&,int n)添加高斯噪声

#ifndef _CREATENOISE
#define _CREATENOISE

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#define TWO_PI 6.2831853071795864769252866

using namespace cv;
using namespace std;

class CreateNoise {
private:
	double generateGaussianNoise();//创建高斯噪声函数原型

public:
	 void AddPepperNoise(Mat& image, int n);//添加椒噪声
	 void AddSaltNoise(Mat& image, int n);//添加盐噪声
	 void AddGaussianNoise(Mat&);//添加高斯噪声
};

#endif