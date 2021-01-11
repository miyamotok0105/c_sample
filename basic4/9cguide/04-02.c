#include <stdio.h>

int main(void)
{
    printf("%d\n",100+200);

    printf("%d\n",10 + 3);
    printf("%d\n",10 - 3);
    printf("%d\n",10 * 3);
    printf("%d\n",10 / 3);
    printf("%d\n",10 % 3);

    //複雑な式。計算の優先順位
    printf("%d\n",(1 + 100) * 100 / 2);

    return 0;
}