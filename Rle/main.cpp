/**
 * @file main.cpp
 * @author lilDengZi
 * @brief rle解压缩算法
 * @version 1.0
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<fstream>
#include<cstring>

/**
 * @brief 压缩
 * @param input_buff 输入缓冲 
 * @param output_buff 输出缓冲 
 * @param length 输入缓冲长度
 * @return 输出缓冲长度
 */
int Encode(unsigned char *input_buff, unsigned char *output_buff, int length)
{
    int left = 0,   ///< 左下标
        right = 0,  ///< 右下标
        flag = -1;  ///< 类型 0 重复 1 不重复
    int out_index = 0;  ///< 输出下标
    while(left < length)
    {
        right++;
        // 判断类型
        if(flag == -1)
        {
            if(input_buff[left] == input_buff[right])
            {
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
        // 压缩重复
        if(flag == 0 && (input_buff[right - 1] != input_buff[right] || right - left >= 128 || right >= length))
        {
            output_buff[out_index++] = (unsigned char)(right - left + 128);
            output_buff[out_index++] = input_buff[left];
            left = right;
            flag = -1;
        }
        // 压缩不重复
        if(flag == 1 && (input_buff[right - 1] == input_buff[right] || right - left >= 128 || right >= length))
        {
            output_buff[out_index++] = (unsigned char)(right - left);
            while(left < right)
            {
                output_buff[out_index++] = input_buff[left++];
            }
            flag = -1;
        }
    }
    return out_index;
}

/**
 * @brief 解压
 * @param input_buff 输入缓冲 
 * @param output_buff 输出缓冲 
 * @param length 输入缓冲长度
 * @return 输出缓冲长度
 */
int Decode(unsigned char* input_buff, unsigned char* output_buff, int length){
	int i = 0;          // 输入下标
    int out_index = 0;  // 输出下标
    while(i < length)
    {
        if(input_buff[i] < 128) // 解压不重复
        {
            int c = input_buff[i];
            while(c--)
                output_buff[out_index++] = input_buff[++i];
            i++;
        }else{  // 解压重复
            int c = input_buff[i] - 128;
            i++;
            while(c--)
                output_buff[out_index++] = input_buff[i];
            i++;
        }
    }
    return out_index;
}

int main(int argc, char *argv[]){
    char *input_path = new char [1024]();
    char *output_path = new char [1024]();
    char *mode = new char[10]();
    // 判断参数
    if(argc <= 3)
    {
        std::cout << "Input path: ";
        std::cin >> input_path;
        std::cout << "Mode: ";
        std::cin >> mode;
        std::cout << "Output path: ";
        std::cin >> output_path;
    }else{
        input_path = argv[1];
        mode = argv[2];
        output_path = argv[3];
    }

	// 打开文件
    std::fstream input_file, output_file;
    input_file.open(input_path, std::ios_base::in);
    output_file.open(output_path, std::ios::out);

	if(!input_file.is_open() || !output_file.is_open()){
		std::cout<<"Can not open files."<<std::endl;
		return 0;
	}

    // 获取文件长度
    int input_length;
    input_file.seekg(0, input_file.end);
    input_length = input_file.tellg();
    input_file.seekg(0, input_file.beg);
    // 初始化缓冲区
	unsigned char* input_buffer = new unsigned char[input_length]();
	unsigned char* output_buffer = new unsigned char[input_length * 128]();

    
    // 读取文件
    input_file.read((char*)input_buffer, input_length);

    // 压缩或解压
    int output_length;
	if(!std::strcmp(mode, "-c")) {
        output_length = Encode(input_buffer, output_buffer, input_length);

	}else{
		output_length = Decode(input_buffer, output_buffer, input_length);
	}

    // 输出文件
    output_file.write((char*)output_buffer, output_length);

    // 关闭文件
    input_file.close();
    output_file.close();

	return 0;
} 
