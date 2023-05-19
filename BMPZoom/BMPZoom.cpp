#include "BMPZoom.h" 
#include <stdlib.h>
#include <ios>

BMPZoom::BMPZoom()
{
    
}

void BMPZoom::zoom(char* str_orig_file_path, int num_zoom_ratio, char * str_output_file_path)
{
    BitMapData* data = LoadImage(str_orig_file_path);
    Scaling(num_zoom_ratio, data);
    SaveImage(str_output_file_path, data);
}

BMPZoom::BitMapData *BMPZoom::LoadImage(char* str_orig_file_path)
{
    BitMapData *data = new BitMapData;
    // 打开图像
    FILE *file;
    fopen_s(&file, str_orig_file_path, "rb");

    if (!file)
    {
        delete data;
        data = nullptr;
        return data;
    }

    // 读取文件头&信息头
    BitMapFileHeader file_header{};
    fread((char*)(&file_header), 1, sizeof(BitMapFileHeader), file);
    BitMapInfoHeader info_header{};
    fread((char*)(&info_header), 1, sizeof(BitMapInfoHeader), file);
    data->file_header = file_header;
    data->info_header = info_header;
    // 文件类型错误
    if(file_header.num_type != 0x4D42 || info_header.num_bit_compression != 0
       || !(info_header.num_bit_count == 24|| info_header.num_bit_count == 32))
    {
        delete data;
        return nullptr;
    }
    // 读取像素信息
    std::vector<PixelData> width_vector;
    width_vector.resize(data->info_header.num_width);
    data->data.resize(data->info_header.num_height, width_vector);

    unsigned char* raw_data = (unsigned char*)malloc(static_cast<size_t>(data->file_header.num_size) - 54);
    memset(raw_data, 0, data->file_header.num_size - 54);
    fread(raw_data, 1, static_cast<size_t>(data->file_header.num_size) - 54, file);

    int index = 0;
    if(data->info_header.num_bit_count == 24)   // 24位色
    {
        int skip = data->info_header.num_width % 4;
        for(int i = 0; i < data->info_header.num_height; i++)
        {
            for(int j = 0; j < data->info_header.num_width; j++)
            {
                data->data[i][j].red = raw_data[index++];
                data->data[i][j].green = raw_data[index++];
                data->data[i][j].blue = raw_data[index++];
            }
            // 读取凑齐位
            for (int k = 0; k < skip; k++)
                index++;
        }
    }else{  // 32位色
        for(int i = 0; i < data->info_header.num_height; i++)
        {
            for(int j = 0; j < data->info_header.num_width; j++)
            {
                data->data[i][j].red = index++;
                data->data[i][j].green = index++;
                data->data[i][j].blue = index++;
                data->data[i][j].alpha = index++;
            }
        }
    }
    // 关闭文件
    fclose(file);

    return data;
}

void BMPZoom::Scaling(int num_zoom_ratio, BitMapData *data)
{
    // 计算缩放参数
    int num_src_width = data->info_header.num_width,            // 原图片宽度
        num_src_height = data->info_header.num_height;          // 原图片高度
    int num_dst_width = num_src_width * num_zoom_ratio / 100,   // 目标图片宽度
        num_dst_height = num_src_height * num_zoom_ratio / 100; // 目标图片高度

    // 创建空的结果待用
    std::vector<std::vector<PixelData>> dst_data, &src_data = data->data;
    std::vector<PixelData> width_vector;
    width_vector.resize(num_dst_width);
    dst_data.resize(num_dst_height, width_vector);

    // 缩放计算
    double num_linear_ratio_x = static_cast<double>(num_src_width - 1) / static_cast<double>(num_dst_width - 1),// 线性插值x比例
        num_linear_ratio_y = static_cast<double>(num_src_height - 1) / static_cast<double>(num_dst_height - 1); // 线性插值y比例
    for(int i = 0; i < num_dst_height; i++)
    {
        double num_linear_y = i * num_linear_ratio_y;   // y插值
        int y1 = static_cast<int>(num_linear_y),        // y插值处上像素坐标
            y2 = y1 + 1;                                // y插值处下像素坐标
        if (y1 >= num_src_height - 1)
            y1 = num_src_height - 2, y2 = num_src_height -1;
        for(int j = 0; j < num_dst_width; j++)
        {
            double num_linear_x = j * num_linear_ratio_x;   // x插值
            int x1 = static_cast<int>(num_linear_x),        // x插值处左像素坐标
                x2 = x1 + 1;                                // x插值处右像素坐标
            if (x1 >= num_src_width -1)
                x1 = num_src_width - 2, x2 = num_src_width -1;

            // 计算二次插值
            dst_data[i][j] = (src_data[y1][x1] * (x2 - num_linear_x) + src_data[y1][x2] * (num_linear_x - x1)) * (y2 - num_linear_y)
                           + (src_data[y2][x1] * (x2 - num_linear_x) + src_data[y2][x2] * (num_linear_x - x1)) * (num_linear_y - y1);

            //PixelData py1 = x1 == x2 ? src_data[y1][x1] : src_data[y1][x1] * (x2 - num_linear_x) + src_data[y1][x2] * (num_linear_x - x1),
            //    py2 = x1 == x2 ? src_data[y2][x1] : src_data[y2][x1] * (x2 - num_linear_x) + src_data[y2][x2] * (num_linear_x - x1);
            //dst_data[i][j] = y1 == y2 ? py1 : py1 * (y2 - num_linear_y) + py2 * (num_linear_y - y1);
        }
    }

    // 保存结果数据
    data->data = dst_data;
    data->info_header.num_size_image = data->info_header.num_bit_count / 8 == 3 ? num_dst_height * (num_dst_width * 3 + num_dst_width % 4) : num_dst_width * num_dst_height * 4;
    data->file_header.num_size = 54 + data->info_header.num_size_image;
    data->info_header.num_width = num_dst_width;
    data->info_header.num_height = num_dst_height;
}

void BMPZoom::SaveImage(char* str_output_file_path, BitMapData *data)
{
    // 打开文件
    FILE* file;
    fopen_s(&file, str_output_file_path, "wb");

    if (!file)
    {
        return;
    }

    // 写入文件头
    fwrite((char*)(&data->file_header), 1, sizeof(BitMapFileHeader), file);
    fwrite((char*)(&data->info_header), 1, sizeof(BitMapInfoHeader), file);
    unsigned char* raw_data = (unsigned char*)malloc(static_cast<size_t>(data->file_header.num_size) - 54);
    memset(raw_data, 0, static_cast<size_t>(data->file_header.num_size) - 54);

    // 写入像素信息
    int index = 0;
    if(data->info_header.num_bit_count == 24)   // 24位色
    {
        int skip = data->info_header.num_width % 4;
        for(int i = 0; i < data->info_header.num_height; i++)
        {
            for(int j = 0; j < data->info_header.num_width; j++)
            {
                raw_data[index++] = data->data[i][j].red;
                raw_data[index++] = data->data[i][j].green;
                raw_data[index++] = data->data[i][j].blue;
            }
            // 写入凑齐位
            for (int k = 0; k < skip; k++)
                raw_data[index++] = 0;
        }
    }else{  // 32位色
        for(int i = 0; i < data->info_header.num_height; i++)
        {
            for(int j = 0; j < data->info_header.num_width; j++)
            {
                raw_data[index++] = data->data[i][j].red;
                raw_data[index++] = data->data[i][j].green;
                raw_data[index++] = data->data[i][j].blue;
                raw_data[index++] = data->data[i][j].alpha;
            }
        }
    }
    fwrite(raw_data, 1, static_cast<size_t>(data->file_header.num_size) - 54, file);

    //关闭文件
    fclose(file);
}
