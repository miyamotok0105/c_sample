#include <stdio.h>

int main(void)
{
    char str[256] = "DRAGON";
    //6番目の要素が入れ替わる
    scanf("%s",&str[6]); /* 6番の要素のアドレス */
    printf("%s\n",str);
    return 0;
}
