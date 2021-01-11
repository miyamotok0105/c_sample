#include <stdio.h>

int main(void) {

    char name[30];
    int age;

    printf("名前をローマ字で入力してください ");
    scanf("%s", name);

    printf("年齢を入力してください ");
    scanf("%d", &age);

    printf("%sさんは%d才です。\n", name, age);

    return 0;
}
