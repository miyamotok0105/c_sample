#include <stdio.h>

int max_return(int a, int b, int c, int d, int e)
{
  int max;

  max = a;

  if(max < b) max = b;
  if(max < c) max = c;
  if(max < d) max = d;
  if(max < e) max = e;

  return max;

}

int main(void)
{
  int d0, d1, d2, d3, d4;
  int max;

  printf("正の整数を5つ入れてください。\n");
  scanf("%d %d %d %d %d", &d0, &d1, &d2, &d3, &d4);

  max = max_return(d0, d1, d2, d3, d4);

  printf("最大値 = %d\n", max);

  return (0);
}
