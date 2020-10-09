#include <stdio.h>

int main(void) {

    double a, b;

    printf("データを2つ入れてください ");
    scanf("%lf%lf", &a,&b);
    //整数部分3桁、小数点以下3桁
    printf("和 = %7.3f\n", a+b);
    printf("差 = %7.3f\n", a-b);
    printf("積 = %7.3f\n", a*b);
    printf("商 = %7.3f\n", a/b);

    return 0;
}
