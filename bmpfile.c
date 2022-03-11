#include <stdio.h>
#include <stdlib.h>
#include "bmpfile.h"
#include "bmpheader.h"

int bmp_load(BMP *pb, char *file)
{
    BMPFILEHEADER *bfh = (BMPFILEHEADER *)malloc(sizeof(BMPFILEHEADER));
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        return 0;
    }
    
    fread(bfh, 1, sizeof(BMPFILEHEADER), fp);
    
    pb->width  = bfh->biWidth;
    pb->height = bfh->biHeight;
    pb->stride = (bfh->biWidth * bfh->biBitCount + 31) / 32 * 4;
    pb->cdepth = bfh->biBitCount;
    
    uint8_t *data = (uint8_t *)malloc(pb->stride * pb->height);
    fread(data, 1, pb->stride * pb->height, fp);
    pb->pdata = data;
    fclose(fp);
    
    return 1;
}

int bmp_save(BMP *pb, char *file)
{
    BMPFILEHEADER bfh;
    bfh.bfType          = 0x4D42;
    bfh.bfSize          = sizeof(BMPFILEHEADER) + pb->height * pb->stride;
    bfh.bfReserved1     = 0;
    bfh.bfReserved2     = 0;
    bfh.bfOffBits       = sizeof(BMPFILEHEADER);
    bfh.biSize          = 40;
    bfh.biWidth         = pb->width;
    bfh.biHeight        = pb->height;
    bfh.biPlanes        = 1;
    bfh.biBitCount      = pb->cdepth;
    bfh.biCompression   = 0;
    bfh.biSizeImage     = pb->height * pb->stride;
    bfh.biXPelsPerMeter = 2835;
    bfh.biYPelsPerMeter = 2835;
    bfh.biClrUsed       = 0;
    bfh.biClrImportant  = 0;
    
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        return 0;
    }
    fwrite(&bfh, 1, sizeof(BMPFILEHEADER), fp);
    fwrite(pb->pdata, 1, pb->width * pb->stride, fp);
    fclose(fp);
    
    return 1;
}

void bmp_free(BMP *pb)
{
    free(pb->pdata);
    free(pb);
    printf("free done.\n");
}

void bmp_setpixel(BMP *pb, int x, int y, int r, int g, int b)
{
    int width  = pb->width;
    int height = pb->height;
    int index  = ((height - y + 1) * width + (x - 1)) * 3;
    *(uint8_t *)(pb->pdata + index) = r;
    *(uint8_t *)(pb->pdata + index + 1) = g;
    *(uint8_t *)(pb->pdata + index + 2) = b;
}

void bmp_getpixel(BMP *pb, int x, int y, int *r, int *g, int *b)
{
    int width  = pb->width;
    int height = pb->height;
    int index  = ((height - y + 1) * width + (x - 1)) * 3;
    *r = *(uint8_t *)(pb->pdata + index);
    *g = *(uint8_t *)(pb->pdata + index + 1);
    *b = *(uint8_t *)(pb->pdata + index + 2);
}




