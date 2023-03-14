# Plate_Det_REC_TensorRT_C++_VS2019
最近准备在工控机端利用TensorRT部署车牌检测和车牌识别，代码从 https://github.com/we0091234/chinese_plate_tensorrt 这位大佬的网址下载的，在自己电脑上部署时需要注意一些细节，在此记录如下

# 环境要求

VS2019（Release x64）

CUDA 11.3

CUDNN 8.6

TensorRT-8.5.1.7.Windows10.x86_64.cuda-11.8.cudnn8.6

Opencv452

**注意：**Tensorrt下载上面要求的cudnn版本一定要与cuda下的cudnn一致，否则可能会报错

# 属性表配置

**Opencv**

VC++目录 -> 包含目录：D:\Library\opencv452\build\include;

VC++目录 -> 库目录：D:\Library\opencv452\build\x64\vc15\lib;

链接器 -> 输入 -> 附加依赖项：opencv_world452.lib

**CUDA**

VC++目录 -> 包含目录：C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.3\include;

VC++目录 -> 库目录：C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.3\lib\x64;

链接器 -> 输入 -> 附加依赖项：C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.3\lib\x64\*.lib;

**TensorRT**

VC++目录 -> 包含目录：D:\Library\TensorRT-8.5.1.7\include;

VC++目录 -> 库目录：D:\Library\TensorRT-8.5.1.7\lib;

链接器 -> 输入 -> 附加依赖项：nvinfer.lib;nvinfer_plugin.lib;nvonnxparser.lib;nvparsers.lib;

**其他配置**

属性表->配置属性->C/C++->预处理器->预处理器定义：NDEBUG; _CONSOLE; _CRT_SECURE_NO_WARNINGS;NOMINMAX;

VC++目录 -> 包含目录：.\common

# 项目解答

从 https://github.com/we0091234/chinese_plate_tensorrt 下载的代码主要是在linux上使用的，但移植到windows上会存在一些问题，现针对碰到的问题解答如下：

（1）编译时报各种未识别变量和乱码的错误

解决办法：需要通过 vs 重新添加 .cpp 和 .h 文件，然后把代码拷贝到该新建文件即可，可能是写代码时编码方式不一样

（2）static char *color_list[]={"黑色","蓝色","绿色","白色","黄色"};报错

解决方法：直接修改为 static std::vector<std::string> color_list = { "黑色","蓝色","绿色","白色","黄色" };

（3）readFileList函数读取不到图片

解决办法：利用read_files_in_dir函数替代

## 联系

**有问题可以提issues 或者加qq群:722237896 询问**

