#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node * next;
};
struct Node * head;

void Insert(int x) {
  struct Node * temp = (struct Node * ) malloc(sizeof(struct Node));
  temp -> data = x;
  temp -> next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    struct Node * temp1 = head;
    while (temp1 -> next != NULL) {
      temp1 = temp1 -> next;
    }
    temp1 -> next = temp;
  }

}

void Print() {
  struct Node * temp = head;

  printf("List is:");
  while (temp != NULL) {
    printf(" %d", temp -> data);
    temp = ( * temp).next;
  }
  printf("\n");
}

void Delete(int position) {
  int i;
  if (position == 1) {
    struct Node * temp2;
    temp2 = head;

    head = temp2 -> next;
  } else {
    struct Node * temp = head;
    for (i = 0; i < position - 2; i++)
      temp = temp -> next;

    struct Node * temp1 = head;
    for (i = 0; i < position; i++)
      temp1 = temp1 -> next;

    temp -> next = temp1;
  }

  Print();
}

int main() {
  head = NULL;
  int n, i, x, position;
  printf("how many numbers?");
  scanf("%d", & n);

  for (i = 0; i < n; i++) {
    printf("now enter the number:\n");
    scanf("%d", & x);
    Insert(x);
    Print();
  }

  for (i = 0; i < n; i++) {
    printf("enter the position which you want to delete from the linked list:\n");
    scanf("%d", & position);
    Delete(position);
  }

  return 0;
}