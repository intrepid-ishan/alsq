#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node * next;
};
struct node * head;

void Insert(int x, int n) {
  int i;
  struct Node * temp1 = (struct Node * ) malloc(sizeof(struct Node));
  temp1 -> data = x;
  temp1 -> next = NULL;

  if (n == 1) {
    temp1 -> next = head;
    head = temp1;
    return;
  }

  struct Node * temp2 = head;
  for (i = 0; i < n - 2; i++) {
    temp2 = temp2 -> next;
  }

  struct Node * temp3 = head;
  for (i = 0; i < n - 1; i++) {
    temp3 = temp3 -> next;
  }

  temp2 -> next = temp1;
  temp1 -> next = temp3;

}
void Print() {
  struct Node * temp = head;

  printf("List is:");
  while (temp != NULL) {
    printf(" %d", temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}

int main() {
  head = NULL;

  Insert(2, 1);
  Insert(3, 2);
  Insert(4, 1);
  Insert(5, 2);
  Print();

  return 0;
}