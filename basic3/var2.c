#include <stdio.h>

int main(void) {

    int a, b;

    printf("データを2つ入れてください ");
    scanf("%d%d", &a,&b);

    // var1との違いはint, 浮動小数点の違い
    printf("和 = %d\n", a+b);
    printf("差 = %d\n", a-b);
    printf("積 = %d\n", a*b);
    printf("商 = %d\n", a/b);

    return 0;
}
