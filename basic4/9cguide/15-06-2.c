#include <stdio.h>

int getaverage(int data[10]);

int main(void)
{
    int average,array[10] = {15,78,98,15,98,85,17,35,42,15};
    average = getaverage(array);
    printf("%d\n",average);

    //引数で要素数は無視される！！！
    int average2,array2[5] = {15,78,98,15,98};
    average2 = getaverage(array2);
    printf("%d\n",average2);

    return 0;
}

//配列型の引数！！！
int getaverage(int data[10])
{
    int i,average = 0;
    for (i = 0;i < 10;i++) {
        average += data[i];
    }
    return average / 10;
}
