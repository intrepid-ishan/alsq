#include<stdio.h>
#include<stdlib.h>

int main() {

  int arr[100], value_insert, position, i, size;

  printf("PLEASE ENTER THE SIZE OF AN ARRAY:");
  scanf("%d", & size);

  printf("enter the elements in array:\n");
  for (i = 0; i < size; i++) {
    scanf("%d", & arr[i]);
  }

  printf("enter the position where you want to enter the element:");
  scanf("%d", & position);

  printf("enter the value to be inserted:\n");
  scanf("%d", & value_insert);

  for (i = size - 1; i >= position - 1; i--) {
    arr[i + 1] = arr[i];
  }

  arr[position - 1] = value_insert;

  printf("the updated array is:");
  for (i = 0; i <= size; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}