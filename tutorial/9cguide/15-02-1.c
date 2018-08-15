#include <stdio.h>

int main(void)
{
    int i;
    //&はメモリの番地
    //メモリの場所はコンパイラが勝手に決める。
    printf("%p\n",&i);

    int i1,i2,i3;
    printf("i1(%p)\n",&i1);
    printf("i2(%p)\n",&i2);
    printf("i3(%p)\n",&i3);


    int array[10];
    // printf("array___(%p)\n",array);
    printf("array0\n",&array[0]);
    // printf("array1\n",&array[1]);
    // printf("array2\n",&array[2]);
    
    return 0;
}
