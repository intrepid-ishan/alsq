#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node * next;
};
struct Node * top;

void Push(int x) {
  struct Node * temp = (struct Node * ) malloc(sizeof(struct Node));
  temp -> data = x;
  ( * temp).next = top;
  top = temp;
}

void Pop() {
  struct Node * temp;
  temp = top;
  if (top == NULL) {
    printf("Stack underflow");
    return;
  }
  top = temp -> next;
  free(temp);
}

void Print() {
  struct Node * temp = top;

  printf("List is:");
  while (temp != NULL) {
    printf(" %d", temp -> data);
    temp = ( * temp).next;
  }
  printf("\n");
}

int main() {
  top = NULL;
  int n, i, x, position;
  printf("how many numbers?");
  scanf("%d", & n);

  for (i = 0; i < n; i++) {
    printf("now enter the number:\n");
    scanf("%d", & x);
    Push(x);
    Print();
  }

  for (i = 0; i < n; i++) {
    printf("Pop():\n");
    Pop();
    Print();
  }
  Pop();
  return 0;
}