#include <stdio.h>

int main(void){

    int n;
    double dat, sum, mean;

    sum=0.0;
    n=0;
    while (scanf("%lf", &dat)!=EOF){
        sum += dat;
        n++;
    }
    printf("合計 = %9.4f\n", sum);

    mean = sum/n;
    printf("平均 = %9.4f\n", mean);

    return 0;
}
