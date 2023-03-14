#pragma once
#ifndef __PLATE_REC__
#define __PLATE_REC__
#include "NvInfer.h"
#include "logging.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>
#include "utils.hpp"
using namespace nvinfer1;

static std::vector<std::string> plate_string = { "#","��","��","��","��","��","��","��","��","��","��","��","��","��", \
"��","��","³","ԥ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ѧ","��","��","��","��","ʹ","��","��","��","��", \
"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","J","K","L","M","N","P","Q","R","S","T","U","V","W","X","Y","Z" };

//static char *color_list[]={"��ɫ","��ɫ","��ɫ","��ɫ","��ɫ"};
static std::vector<std::string> color_list = { "��ɫ","��ɫ","��ɫ","��ɫ","��ɫ" };


class PlateRec
{
public:
	PlateRec();
	void loadTrtModel(const char* trtmodel, Logger& gLogger);
	void plate_rec_color(cv::Mat& img, cv::Size size, std::string& plate_no, std::string& plate_color);
	~PlateRec();

private:
	IRuntime* runtime = nullptr;
	ICudaEngine* engine = nullptr;
	IExecutionContext* context = nullptr;
	float* prob_1 = nullptr;  //�ַ�ʶ�����
	float* prob_2 = nullptr;  //��ɫʶ�����
	float* blob = nullptr;    //tensorrt ����

	int output_size_color = 5; //��ɫ5��
	int time_step = 21;   //ʱ�䲽��������ֵ��������ַ�����
	int num_char = 78; //�ַ������  ����78������ַ�
	float mean_value = 0.588;  //��ֵ
	float std_value = 0.193;   //����
	int output_size = time_step * num_char;  //�ַ�ʶ�������С
	const char* plate_rec_input_name = "images"; //onnx ����  ����
	const char* plate_rec_out_name_1 = "output_1"; //onnx �ַ�ʶ���֧
	const char* plate_rec_out_name_2 = "output_2"; //onnx ��ɫʶ���֧
};


#endif