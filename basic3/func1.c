/* 
    BMI (Body Mass Index) の計算方法：関数の利用
*/

#include <stdio.h>


double bmi_cal(double h, double w) {

  /* BMI = 体重(kg) / 身長(m) / 身長(m) */

  return w/h/h;
}


int main(void) {

  double height, weight, bmi;

  printf("身長(m)と体重(kg)を入力してください ");
  scanf("%lf%lf", &height, &weight);

  /* BMIの計算 */
  bmi = bmi_cal(height, weight);
  
  printf("身長%5.2f m、体重%6.2f kgの人のBMI = %6.2f\n", height, weight, bmi);  

  return (0);
}
