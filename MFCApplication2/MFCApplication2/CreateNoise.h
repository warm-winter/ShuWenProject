/*-----------CreateNoise��-------------------*/
//CreateNoise.h�ļ�
//���ܣ�����ͼ������
//ʹ�ã����ó�Ա����void AddGaussianNoise(Mat&)��Ӹ�˹����
//���ó�Ա����void AddPepperNoise(Mat&int n)��Ӹ�˹����
//���ó�Ա����void AddSaitNoise(Mat&,int n)��Ӹ�˹����

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
	double generateGaussianNoise();//������˹��������ԭ��

public:
	 void AddPepperNoise(Mat& image, int n);//��ӽ�����
	 void AddSaltNoise(Mat& image, int n);//���������
	 void AddGaussianNoise(Mat&);//��Ӹ�˹����
};

#endif