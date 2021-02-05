#include<stdio.h>
#include<stdlib.h>


struct Node {
  int data;
  struct Node * next;
  struct Node * prev;
};
struct Node * head;

void create_list();
void display();
void add_to_empty(int data);
void add_at_beg(int data);
void add_at_end(int data);
void add_after(int data, int item);
void add_before(int data, int item);
void del(int data);

void create_list() {
  int n, i, data;
  printf("Enter the number of nodes:");
  scanf("%d", & n);

  if (n == 0) return;

  printf("Enter the data to be inserted:");
  scanf("%d", & data);
  add_to_empty(data);

  for (i = 0; i < n - 1; i++) {
    printf("Enter the data to be inserted:");
    scanf("%d", & data);
    add_at_end(data);
  }
}

void display() {
  struct Node * temp;
  temp = head;

  if (head == NULL) {
    printf("The list is empty:");
    return;
  }
  printf("\nThe list is : ");
  while (temp != NULL) {
    printf(" %d", temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}

void add_to_empty(int x) {
  struct Node * newnode = (struct Node * ) malloc(sizeof(struct Node));

  newnode -> data = x;
  newnode -> next = NULL;
  newnode -> prev = NULL;
  head = newnode;
}

void add_at_end(int x) {
  struct Node * newnode = (struct Node * ) malloc(sizeof(struct Node));
  struct Node * temp;
  temp = head;

  while (temp -> next != NULL) {
    temp = temp -> next;
  }

  temp -> next = newnode;
  newnode -> data = x;
  newnode -> prev = temp;
  newnode -> next = NULL;
}

void add_at_beg(int x) {
  struct Node * newnode = (struct Node * ) malloc(sizeof(struct Node));

  if (head == NULL) {
    add_to_empty(x);
  }
  newnode -> next = head;
  newnode -> prev = NULL;
  newnode -> data = x;
  head = newnode;
}

void add_after(int x, int item) {
  struct Node * temp;
  temp = head;
  struct Node * newnode = (struct Node * ) malloc(sizeof(struct Node));
  newnode -> data = x;

  if (head == NULL) {
    printf("The list is empty\n");
  }

  while (temp != NULL) {

    if (temp -> data == item) {
      newnode -> next = temp -> next;
      newnode -> prev = temp;

      if (temp -> next != NULL)
        temp -> next -> prev = newnode;

      temp -> next = newnode;
      return;
    }
    temp = temp -> next;
  }

  printf("%d not found", item);
}

void add_before(int x, int item) {
  struct Node * newnode;
  struct Node * temp;
  if (head == NULL) {
    printf("The list is empty\n");
    return;
  }

  if (head -> data == item) {
    newnode = (struct Node * ) malloc(sizeof(struct Node));
    newnode -> data = x;
    newnode -> prev = NULL;
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    return;
  }
  temp = head;
  while (temp != NULL) {

    if (temp -> data == item) {
      newnode = (struct Node * ) malloc(sizeof(struct Node));
      newnode -> data = x;;
      newnode -> prev = temp -> prev;
      newnode -> next = temp;
      temp -> prev -> next = newnode;
      temp -> prev = newnode;
      return;
    }
    temp = temp -> next;
  }

  printf("%d not found", item);
}

void del(int x) {
  struct Node * temp;

  if (head -> data == x) {
    head = head -> next;
    return;
  }

  temp = head;
  while (temp != NULL) {
    if (temp -> data == x) {
      temp -> prev -> next = temp -> next;
      temp -> next -> prev = temp -> prev;
      return;
    }
    temp = temp -> next;
  }
  printf("%d not found", x);
}

void reverse() {
  struct Node * temp;
  temp = head;
  if (temp == NULL) return;

  while (temp -> next != NULL) {
    temp = temp -> next;
  }
  printf("Reverse: ");
  while (temp != NULL) {
    printf("%d", temp -> data);
    temp = temp -> prev;
  }
  printf("\n");
}

int main() {
  head == NULL;
  int choice, data, item;
  while (1) {
    printf("1.Create List\n");
    printf("2.Display\n");
    printf("3.Add to empty list\n");
    printf("4.Add at beginning\n");
    printf("5.Add at end\n");
    printf("6.Add after\n");
    printf("7.Add before\n");
    printf("8.Delete\n");
    printf("9.Reverse\n");
    printf("10.Quit\n");
    printf("Enter your choice : ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      create_list();
      break;
    case 2:
      display();
      break;
    case 3:
      printf("Enter the element to be inserted : ");
      scanf("%d", & data);
      add_to_empty(data);
      break;
    case 4:
      printf("Enter the element to be inserted : ");
      scanf("%d", & data);
      add_at_beg(data);
      break;
    case 5:
      printf("Enter the element to be inserted : ");
      scanf("%d", & data);
      add_at_end(data);
      break;
    case 6:
      printf("Enter the element to be inserted : ");
      scanf("%d", & data);
      printf("Enter the element after which to insert : ");
      scanf("%d", & item);
      add_after(data, item);
      break;
    case 7:
      printf("Enter the element to be inserted : ");
      scanf("%d", & data);
      printf("Enter the element before which to insert : ");
      scanf("%d", & item);
      add_before(data, item);
      break;
    case 8:
      printf("Enter the element to be deleted : ");
      scanf("%d", & data);
      del(data);
      break;
    case 9:
      reverse();
      break;
    case 10:
      exit(1);
    default:
      printf("Wrong choice\n");
    }
  }
  return 0;
}