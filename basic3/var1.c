//gcc var1.c
//a.out

#include <stdio.h>

int main(void) {

    double a, b;

    //&aポインタ
    printf("データを2つ入れてください ");
    scanf("%lf%lf", &a,&b);

    printf("和 = %f\n", a+b);
    printf("差 = %f\n", a-b);
    printf("積 = %f\n", a*b);
    printf("商 = %f\n", a/b);

    return 0;
}