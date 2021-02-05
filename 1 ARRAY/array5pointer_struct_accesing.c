#include<stdio.h>
#include<stdlib.h>

struct person {
  int data_score;
};

int main() {
  struct person * p;
  p -> data_score = 100;
  printf("\n the value accessed by pointer of the structure is %d", p -> data_score);
}