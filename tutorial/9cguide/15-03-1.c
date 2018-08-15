#include <stdio.h>

int main(void)
{
    char str[256];
    //0番目のアドレスに値を入れる
    scanf("%s",&str[0]); /* 0番の要素のアドレス */
    printf("%s\n",str);
    return 0;
}
