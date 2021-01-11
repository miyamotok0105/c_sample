#include <stdio.h>

int main(void) {

    int i;
    //初期化
    int data[10]={2,3,0,9,12,8,9,-2,7,6};


    for (i=0; i<10; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    return (0);
}
