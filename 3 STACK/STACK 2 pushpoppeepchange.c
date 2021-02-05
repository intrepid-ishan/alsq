#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void change();
void push(int item);
void pop();
void peep();
int isEmpty();
int isFull();
void display();

int main() {
  int choice, item;

  while (1) {
    printf("\n1.Push\n");
    printf("2.Pop\n");
    printf("3.Peep\n");
    printf("4.Display all stack elements\n");
    printf("5.change\n");
    printf("6.Quit\n");
    printf("Enter your choice : ");
    scanf("%d", & choice);
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) {
      switch (choice) {
      case 1:
        printf("Enter the item to be pushed : ");
        scanf("%d", & item);
        push(item);
        break;
      case 2:
        pop();
        break;
      case 3:
        peep();
        break;
      case 4:
        display();
        break;
      case 5:
        change();
        break;
      case 6:
        exit(1);
      default:
        printf("Wrong choice\n");
      }
    } else {
      printf("Please renter the correct choice:Between 1-6");
    }
  }

  return 0;
}

void push(int item) {
  if (isFull()) {
    printf("\n\n\nStack Overflow\n\n\n");
    return;
  }
  top = top + 1;
  stack_arr[top] = item;
}

void pop() {
  int item;
  if (isEmpty()) {
    printf("\n \n \n Stack Underflow\n");
    printf("Please push the elements to pop again\n \n \n ");
    return;
  }
  item = stack_arr[top];
  top = top - 1;
  printf("The poped item is %d:", stack_arr[top]);
}

void peep() {
  if (isEmpty()) {
    printf("Stack Underflow\n");
    return;
  }
  int n;
  printf("Enter the position of the number which you want from bottom\n");
  scanf("%d", & n);
  printf("The peeped number is %d\n", stack_arr[n - 1]);
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements :");
  printf("\n\n\n");
  for (i = top; i >= 0; i--)
    printf(" \n%d\n", stack_arr[i]);
  printf("\n\n\n");
}

void change() {

  if (isEmpty()) {
    printf("Stack Underflow\n");
    return;
  }
  int pos;
  printf("Enter the position(bottom) which you want to change:\n ");
  scanf("%d", & pos);
  int c_n;
  printf("Enter the number which you want to replace:");
  scanf("%d", & c_n);

  stack_arr[pos - 1] = c_n;

}
int isEmpty() {
  if (top == -1)
    return 1;
  else
    return 0;
}

int isFull() {
  if (top == MAX - 1)
    return 1;
  else
    return 0;
}