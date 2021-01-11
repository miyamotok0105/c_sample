#include <stdio.h>
#include "sub.h"

//グローバル変数扱い
extern int ans;
void add(int a,int b){
    ans = a + b;
}
 
void sub(int a,int b){
    ans = a - b;
}
