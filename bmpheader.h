#ifndef  _BMPHEADER_H_
#define  _BMPHEADER_H_
#include <stdint.h>

#pragma pack(1)
typedef struct {
    uint16_t bfType;            //文件类型
    uint32_t bfSize;            //文件大小，字节为单位
    uint16_t bfReserved1;       //保留，必须为0
    uint16_t bfReserved2;       //保留，必须为0
    uint32_t bfOffBits;         //从文件头开始的偏移量
    uint32_t biSize;            //该结构的大小
    uint32_t biWidth;           //图像的宽度，以像素为单位
    uint32_t biHeight;          //图像的高度，以像素为单位
    uint16_t biPlanes;          //为目标设备说明位面数，其值总是设为1
    uint16_t biBitCount;        //位深度
    uint32_t biCompression;     //图像数据压缩类型
    uint32_t biSizeImage;       //图像大小，以字节为单位
    uint32_t biXPelsPerMeter;   //水平分辨率，像素/米
    uint32_t biYPelsPerMeter;   //垂直分辨率，同上
    uint32_t biClrUsed;         //位图实际使用的彩色表中的颜色索引数
    uint32_t biClrImportant;    //对图像显示有重要影响的颜色索引的数目
} BMPFILEHEADER;
#pragma ()

#endif