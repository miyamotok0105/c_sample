#include <stdio.h>

int main(void){

    int i, j, sum;

    i = 1;
    j = 1;
    sum = 0;

    while (sum < 10000){
       sum += j;
       printf("%2d日目までの合計金額  %8d円\n", i, sum);
       i++;
       j *= 2;
    }

    return 0;
}