#include "pch.h"
#include "CreateNoise.h"
//CreateNoise.cpp�ļ�
/*��ͼ����Ӹ�˹����*/

//������˹����
 double CreateNoise::generateGaussianNoise() {
	static bool hasSpare = false;
	static double rand1, rand2;

	if (hasSpare)
	{
		hasSpare = false;
		return sqrt(rand1) * sin(rand2);
	}

	hasSpare = true;

	rand1 = rand() / ((double)RAND_MAX);
	if (rand1 < 1e-100) rand1 = 1e-100;
	rand1 = -2 * log(rand1);
	rand2 = (rand() / ((double)RAND_MAX)) * TWO_PI;

	return sqrt(rand1) * cos(rand2);
}

//��˹����
void CreateNoise::AddGaussianNoise(Mat& I) {
	// accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	int channels = I.channels();

	int nRows = I.rows;
	int nCols = I.cols * channels;

	if (I.isContinuous()) {
		nCols *= nRows;
		nRows = 1;
	}

	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i) {
		p = I.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j) {
			double val = p[j] + generateGaussianNoise() * 32;
			if (val < 0)
				val = 0;
			if (val > 255)
				val = 255;

			p[j] = (uchar)val;

		}
	}

}

//������
void CreateNoise::AddSaltNoise(Mat& image, int n) {//nΪ�����Ŀ
	int i, j;
	for (int k = 0; k < n / 2; k++) {

		// rand() is the random number generator
		i = std::rand() % image.cols; // % ����ȡ���������,rand=1022,cols=1000,rand%cols=22
		j = std::rand() % image.rows;

		if (image.type() == CV_8UC1) { // gray-level image

			image.at<uchar>(j, i) = 255; //at������Ҫָ��Mat��������ֵ����,��uchar��

		}
		else if (image.type() == CV_8UC3) { // color image

			image.at<cv::Vec3b>(j, i)[0] = 255; //cv::Vec3bΪopencv�����һ��3��ֵ����������
			image.at<cv::Vec3b>(j, i)[1] = 255; //[]ָ��ͨ����B:0��G:1��R:2
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}
}

//������
void CreateNoise::AddPepperNoise(Mat& image, int n) {//nΪ�����Ŀ

	int i, j;
	for (int k = 0; k < n; k++) {

		// rand() is the random number generator
		i = std::rand() % image.cols; // % ����ȡ���������,rand=1022,cols=1000,rand%cols=22
		j = std::rand() % image.rows;

		if (image.type() == CV_8UC1) { // gray-level image

			image.at<uchar>(j, i) = 0; //at������Ҫָ��Mat��������ֵ����,��uchar��

		}
		else if (image.type() == CV_8UC3) { // color image

			image.at<cv::Vec3b>(j, i)[0] = 0; //cv::Vec3bΪopencv�����һ��3��ֵ����������
			image.at<cv::Vec3b>(j, i)[1] = 0; //[]ָ��ͨ����B:0��G:1��R:2
			image.at<cv::Vec3b>(j, i)[2] = 0;
		}
	}
}