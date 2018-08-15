#include <stdio.h>

int main(void)
{
    //%dで埋め込み文字列
    printf("%d円\n",100);

    printf("%d+",100);
    printf("%d=",200);
    printf("%d\n",300);
    printf("%d+%d=%d\n",100,200,300);
    return 0;
}
