#include <stdio.h>

int size = 10;
int s[10];
int top = -1;
void push(int data);
void pop();
void display();

int main() {
  push(2);
  push(3);
  push(4);
  pop();
  display();
}

void push(int data) {
  if (top == size - 1) {
    // stack full
    return;
  } else {
    s[++top] = data;
  }
}

void pop() {
  if (top == -1) {
    // empty
    return;
  } else {
    top--;
  }
}

void display() {
  for (int i = top; i >=0; i--) {
    printf("%d ",s[i]);
  }
  
}