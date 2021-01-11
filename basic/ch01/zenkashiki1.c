//gcc 001hello.c
#include <stdio.h>

long combi(int, int);
void calcZenkashiki();
long result10c5();

void main(void)
{
  int n;
  int r;

  printf("\n /////////////////////////// \n");
  for(n=0; n<=10;n++){
    for(r=0;r<=n;r++){
      printf("%dC%d=%ld ", n, r, combi(n, r));
    }
    printf("\n");
  }
  printf("\n /////////////////////////// \n");
  printf("組み合わせ数 \n");
  printf("10C5=%ld \n", result10c5());
  printf("10C5=%ld \n", combi(10, 5));
  printf("\n /////////////////////////// \n");
  calcZenkashiki();
}

//10C5=252
//10!/5!・5!=10*9*8*7*6*5*4*3*2/(5*4*3*2)*(5*4*3*2)
long result10c5()
{
  int a = (5*4*3*2)*(5*4*3*2);
  int b = 10*9*8*7*6*5*4*3*2;
  return b/a;
}

long combi(int n, int r)
{
  int i;
  long p = 1;
  for(i=1; i<=r; i++)
    p = p * (n-i+1)/i;
  return p;
}

void calcZenkashiki()
{
  int a[3] = {1, 2};
  int until = 5;
  printf("初期条件:\na0 = %d\na1 = %d\n\n", a[0], a[1]);
  printf("解: \n");
  for (int i = 2; i <= until; ++i) {
      a[2] = 4 * a[1] - a[0];
      printf("a%d = %d\n", i, a[2]);
      a[0] = a[1];
      a[1] = a[2];
  }
}
