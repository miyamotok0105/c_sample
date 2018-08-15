#include <stdio.h>

int main(void)
{
    int *p;
    int i;
    //変数iのアドレスをpポインタに代入。
    p = &i;

    //*記号がつけられたポインタ変数は、通常変数と全く同じ機能
    *p = 10; /* 通常変数モードに切り替えたポインタ変数に代入 */
    printf("p = %d\n",*p);
    printf("i = %d\n",i);
    return 0;
}

