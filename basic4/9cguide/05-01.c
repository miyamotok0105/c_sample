#include <stdio.h>

int main(void)
{
    int value;  /* 変数宣言の部分 */
    value = 10; /* 代入の部分 */
    printf("%d\n",value);   /* 表示の部分 */


    //代入と演算を同時
    value = 10 + 30;
    printf("%d\n",value);


    //インクリメント、デクリメント
    value = 10;
    printf("%d\n",value);
    value++;
    printf("%d\n",value);
    value--;
    printf("%d\n",value);


    return 0;
}