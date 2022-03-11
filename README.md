bmp operate version1.0

### bmp_operate
实现功能：
- 在bmp位图上画矩形框

待改进点：
- 输入的坐标有限制 x1<x2 ，y1<y2

### bmpfile
- 加载bmp
- 保存bmp
- 释放bmp
- 在bmp上绘像素点
- 在bmp上取像素点

待改进点：
- 像素点操作未考虑bmp格式的4字节对齐，bmp图片在某些尺寸下可能显示会有问题
