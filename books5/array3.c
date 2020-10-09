#include <stdio.h>

int main(void) {

    int i, n;
    double data[100];

    printf("数字を入力してください。\n");
    printf("入力を終えるときにはCtrl-dを押してください。\n");

    n = 0;
    while (scanf("%lf", &data[n]) != EOF) {
        n++;
    }

    for (i=0; i<n; i++) {
        printf("data[%d] = %f\n", i, data[i]);
    }

    return (0);
}
