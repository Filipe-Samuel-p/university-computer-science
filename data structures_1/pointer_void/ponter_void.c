#include <stdio.h> 




int main(void){

  void *p;
  int i = 7;
  float f = 23.5;

  p = &i;
  printf("i contem %d\n", *((int *) p));

  p = &f;
  printf("i contem %f\n", *((float *) p));


    return 0;
}