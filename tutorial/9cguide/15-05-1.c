#include <stdio.h>

int main(void)
{
    //ポインタ型
    int *p;
    int i;
    p = &i;

    //どちらもポイントなので、アドレスを返す
    printf("p = %p\n",p);
    printf("&i = %p\n",&i);
    return 0;
}
