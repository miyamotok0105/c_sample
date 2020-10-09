#include <stdio.h>

int main(void) {

    int x;

    printf("数字を1つ入力してください ");
    scanf("%d", &x);

    if (x > 0){ 
        printf("正です\n");
    } else if (x < 0){
        printf("負です\n");
    } else {
        printf("0です\n");
    }

    return 0;
}
