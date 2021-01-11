#include <stdio.h>

int main(void)
{
    int data;
    scanf("%d",&data);  /* 入力部分 */
    printf("%d\n",data);

    //実数の場合、%lf指定子を使用
    double data2;
    scanf("%lf",&data2); /* 入力部分 */
    printf("%f\n",data2);


    //連続でscanfに入れれる
    int data3,data4;
    scanf("%d%d",&data3,&data4);    /* 入力部分 */
    printf("%d , %d\n",data3,data4);

    return 0;
}
