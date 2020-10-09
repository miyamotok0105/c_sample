#include <stdio.h>

int main(void) {

    int i;
    int data[10];


    for (i=0; i<10; i++) {
        data[i] = 3 * i + 10;
    }

    for (i=0; i<10; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    return (0);
}
