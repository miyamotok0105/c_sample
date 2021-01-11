#include<stdio.h>
#include"ppmlib.h"


int main(){

    printf("start !! ¥r¥n");
    int x, y, col;

    load_color_image(0, "");
    // for(y=0;y<height[0];y++){
    //     for(x=0;width[0];x++){
    //         for(col=0;col<3;col++){
    //             image[0][x][y][col] = 255 - image[0][x][y][col];
    //         }
    //     }
    // }
    save_color_image(0, "");
    return 0;
}

