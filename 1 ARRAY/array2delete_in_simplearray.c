#include<stdio.h>

int main() {

  int * p;
  int a[5];
  int i;

  p = & a;

  printf("enter the elements of array");
  for (i = 0; i < 5; i++) {
    scanf("%d", & a[i]);
  }

  for (i = 0; i < 5; i++) {
    printf("%d", *(p + i));
  }
  return 0;
}