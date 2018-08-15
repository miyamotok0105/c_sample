#include <stdio.h>

int getaverage(int data[10]);

int main(void)
{
int average,array[10] = {15,78,98,15,98,85,17,35,42,15};
    printf("array[3] = %d\n",array[3]);
    average = getaverage(array);
    printf("array[3] = %d\n",array[3]);
    printf("%d\n",average);
    return 0;
}

int getaverage(int data[10])
{
    int i,average = 0;
    for (i = 0;i < 10;i++) {
        average += data[i];
    }
    //変なことに関数内で配列の値を変えるとメモリが書き換わる！！！！！
    //配列自体は値渡しされていない。配列はメモリが渡されてる
    data[3] = 111; /* 引数の配列の値を変更 */
    return average / 10;
}
