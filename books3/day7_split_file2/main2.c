#include <stdio.h>
#include "sub.h"
#include "sub2.h"

//  計算の答え（グローバル変数）
int ans = 0;
 

 
int main(){
    int a = 2,b = 3;
    printf("%d + %d = \n",a,b);
    add(a,b);
    showAnswer();
    printf("%d - %d = \n",a,b);
    sub(a,b);
    showAnswer();
}
 

