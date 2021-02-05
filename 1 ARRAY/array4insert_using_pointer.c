#include<stdio.h>
#include<stdlib.h>

int a[100] = {
  1,
  2,
  3,
  4,
  5
};
int * p = a;

void Insert(int z, int position, int size) {
  int i;
  for (i = size - 1; i >= position - 1; i--) {
    p[i + 1] = p[i];
  }
  p[position - 1] = z;
}

void Print(int position, int size) {
  int i;
  printf("\nthe updated array is:\n");
  for (i = 0; i <= size; i++) {
    printf(" %d", *(p + i));
  }

}

int main() {
  Insert(9, 2, 5);
  Print(2, 5);
  Insert(8, 5, 6);
  Print(5, 6);
  return 0;
}