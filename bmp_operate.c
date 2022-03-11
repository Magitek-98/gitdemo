#include <stdio.h>
#include <stdlib.h>
#include "bmpfile.h"
#include "bmpheader.h"

void box_rect(BMP *pb, int x1, int y1, int x2, int y2);

int main() {
    int x, y;
    
    BMP *pb = malloc(sizeof(BMP));
    if (bmp_load(pb, "test.bmp")) {
        printf("load success\n");
    } else {
        printf("load fail\n");
    }
    
    box_rect(pb, 200, 200, 900, 700);
    
    if (bmp_save(pb, "save.bmp")) {
        printf("save success\n");
    } else {
        printf("save fail\n");
    }
    
    bmp_free(pb);
    
    return 0;
}

void box_rect(BMP *pb, int x1, int y1, int x2, int y2)
{
    int index;
    if (x1 > pb->width || x1 < 0) {
        printf("横坐标1越界\n");
        return ;
    } else if (x2 > pb->width || x2 < 0) {
        printf("横坐标2越界\n");
        return ;
    } else if (y1 > pb->height || y1 < 0) {
        printf("纵坐标1越界\n");
        return ;
    }  else if (y2 > pb->height || y2 < 0) {
        printf("纵坐标2越界\n");
        return ;
    } else {
        for (index = x1; index < x2; index++) {
            bmp_setpixel(pb, index, y1, 0, 0, 0);
        }
        for (index = y1; index < y2; index++) {
            bmp_setpixel(pb, x1, index, 0, 0, 0);
        }
        for (index = x1; index < x2; index++) {
            bmp_setpixel(pb, index, y2, 0, 0, 0);
        }
        for (index = y1; index < y2; index++) {
            bmp_setpixel(pb, x2, index, 0, 0, 0);
        }
    }
}


