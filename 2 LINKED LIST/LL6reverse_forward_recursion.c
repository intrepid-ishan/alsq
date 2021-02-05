#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node * next;
};

struct Node * Insert(struct Node * head, int x) {
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

  return head;
}

void Reverse(struct Node * temp) {

  if (temp == NULL) {
    return;
  }
  Reverse(temp -> next);
  printf("%d  ", temp -> data);

}

void Forward(struct Node * temp) {
  if (temp == NULL) return;
  printf("%d  ", temp -> data);
  Forward(temp -> next);
}

void Print(struct Node * head) {

  printf("List is:");
  while (head != NULL) {
    printf(" %d", head -> data);
    head = ( * head).next;
  }
  printf("\n");
}

int main() {
  struct Node * head = NULL;
  int n, i, x, position;
  printf("how many numbers?");
  scanf("%d", & n);

  for (i = 0; i < n; i++) {
    printf("now enter the number:\n");
    scanf("%d", & x);
    head = Insert(head, x);
    Print(head);
  }
  printf("Reverse list is:");
  Reverse(head);
  printf("\n");
  printf("Forward list is:");
  Forward(head);
}