#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
} *ptr;

struct node *top = NULL;
struct node *push(struct node *, int);
struct node *pop(struct node *);
struct node *display(struct node *);

struct node *push(struct node *top, int val) {
  ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data = val;
  if (top == NULL) {
    top=ptr;
    top->next=NULL;
  } else {
    ptr->next=top;
    top=ptr;
  }
  return top;
}