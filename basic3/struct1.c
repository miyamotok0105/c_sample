#include <stdio.h>
#define NUM 4

int main(void)
{
  int i;
  //構造体
  struct student{
    char name[20];
    int english;
    int math;
    int japanese;
  };

  static struct student data[]={{"佐藤", 82, 72, 58},
            {"秋山", 77, 82, 79}, 
            {"永田", 52, 62, 39}, 
            {"藤田", 61, 82, 88}}; 


  for(i=0; i<NUM; i++){
    printf("%10s: 英語=%3d   数学=%3d   国語=%3d\n", 
    data[i].name, data[i].english, data[i].math, data[i].japanese);
  }

  return 0;
}
