#ifndef BMPZOOM_H
#define BMPZOOM_H

#include<fstream>
#include<string>
#include<vector>
#include <cmath>

const std::string g_str_usage = "Usage: $ zoom <Original File> <Zoom Ratios> <Output File>\nOnly 24-bit or 32-bit non-compressed Image Supported."; ///< 用法

class BMPZoom
{
public:
    BMPZoom();
    
    /**
     * @brief 位图文件头
     */
#pragma pack(push,1) //内存对齐2字节
    struct BitMapFileHeader
    {
        unsigned short num_type = 0;        ///< 文件类型
        unsigned long num_size = 0;         ///< 文件大小
        unsigned short num_reserved_1 = 0;  ///< 保留1
        unsigned short num_reserved_2 = 0;  ///< 保留2
        unsigned long num_offset = 0;       ///< 文件头到图像数据地址偏移
    };
#pragma pack(pop)

    /**
     * @brief 位图信息头
     */
#pragma pack(push,1) //内存对齐2字节
    struct BitMapInfoHeader
    {
        unsigned long num_size = 40;            // 信息头大小
        long num_width = 0;                     // 宽度
        long num_height = 0;                    // 高度
        unsigned short num_planes = 0;          // 平面数
        unsigned short num_bit_count = 0;       // 图像位数
        unsigned long num_bit_compression = 0;  // 压缩方式
        unsigned long num_size_image = 0;       // 图像大小
        long num_X_pels_per_meter = 0;          // 水平分辨率
        long num_Y_pels_per_meter = 0;          // 垂直分辨率
        unsigned long num_clr_used = 0;         // 调色板索引数
        unsigned long num_clr_important = 0;    // 重要调色板索引数
    };
#pragma pack(pop)

    /**
     * @brief 像素数据
     */
    struct PixelData
    {
        unsigned char red = 0, green = 0, blue = 0, alpha = 0;
        PixelData operator +(const PixelData& a)
        {
            PixelData x;
            x.red = this->red + a.red;
            x.green = this->green + a.green;
            x.blue = this->blue + a.blue;
            x.alpha = this->alpha + a.alpha;
            return x;
        }
        PixelData operator *(const double& a)
        {
            PixelData x;
            x.red = static_cast<unsigned char>(this->red * a);
            x.green = static_cast<unsigned char>(this->green * a);
            x.blue = static_cast<unsigned char>(this->blue * a);
            x.alpha = static_cast<unsigned char>(this->alpha * a);
            return x;
        }
    };

    /**
     * @brief 位图数据
     */
    struct BitMapData
    {
        BitMapFileHeader file_header{}; // 文件头
        BitMapInfoHeader info_header{}; // 信息头
        std::vector<std::vector<PixelData>> data; // 位图数据
    };

    /**
     * @brief 缩放
     * @param str_orig_file_path 源文件路径
     * @param num_zoom_ratio 缩放倍率
     * @param str_output_file_path 输出文件路径
     */
    void zoom(char *str_orig_file_path, int num_zoom_ratio, char *str_output_file_path);

private:

    /**
     * @brief 读取位图
     * @param str_orig_file_path 源文件路径
     * @return 位图数据
     */
    BitMapData* LoadImage(char* str_orig_file_path);

    /**
     * @brief 缩放
     * @param num_zoom_ratio 缩放倍率
     * @param data 位图数据
     */
    void Scaling(int num_zoom_ratio, BitMapData *data);

    /**
     * @brief 读取位图
     * @param str_output_file_path 输出文件路径
     * @param data 位图数据
     */
    void SaveImage(char* str_output_file_path, BitMapData *data);
};

#endif // BMPZOOM_H