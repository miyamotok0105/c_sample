#include <stdio.h>

int main(void) {

    int i, x;

    printf("数字を1つ入力してください ");
    scanf("%d", &x);

    for (i=1; i<=x; i++){ 
        printf("%d回目の表示\n", i);
    }

    return (0);
}
