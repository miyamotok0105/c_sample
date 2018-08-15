#include <stdio.h>


//プロトタイプ宣言しないと、コンパイルエラーになる。
//warning: implicit declaration of function 'sum' is invalid in C99 [-Wimplicit-function-declaration]

int sum(void);  /* プロトタイプ宣言 */

int main(void)
{
    sum();      /* 呼び出し部分 */
    return 0;
}

int sum(void)
{
    printf("%d\n",(1 + 100) * 100 / 2);
    return 0;
}