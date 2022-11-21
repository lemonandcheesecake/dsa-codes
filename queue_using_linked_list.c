// Implementation of queue using linked list

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
} *rear, *front, *curr;

void enqueue(int);
int dequeue();
void display();

void enqueue(int data) {
  curr = (struct node *)malloc(sizeof(struct node));
  curr->data = data;
  curr->link = NULL;
  if (rear == NULL) { // empty
    rear = curr;
    front = curr;
  } else {
    rear->link = curr;
    rear = curr;
  }
}

int dequeue() {
  int d;
  if (front == NULL) {
    printf("Underflow");
    return 0;
  }
  else {
    d = front->data;
    curr = front;
    front = front->link;
    free(curr);
    return d;
  }
}

void display() {
  curr = front;
  if (front == NULL)
    printf("\nQueue empty!\n");
  else if (front == rear)
    printf("\nQueue is:%d", curr->data);
  else {
    printf("\nQueue is:\n");
    while (curr->link != NULL) {
      printf("%d\t", curr->data);
      curr = curr->link;
    }
    printf("%d\n", curr->data);
  }
}
 
void main() {
  int op, data;
  clrscr();
  do {
    printf("\nQUEUE OPERATIONS:\n1.Enqueue\n2.Dequeue\n3.Exit\n");
    printf("Enter the operation to be performed:");
    scanf("%d", &op);
    switch (op) {
    case 1: {
      printf("Enter the element to be inserted:");
      scanf("%d", &data);
      enqueue(data);
      break;
    }
    case 2: {
      data = dequeue();
      if (data)
        printf("Deleted element: %d", data);
      break;
    }
    case 3:
      break;
    default:
      printf("\nEnter a proper option!\n");
    }
    display();
  } while (op != 3);
  getch();
}
 