#include <stdio.h>
int queue[10], front = 0, rear = -1, count = 0;
void push(int n) {
  queue[++rear] = n;
  count++;
}
void pop(void) {
  if (count == 0)
    printf("Queue is empty\n");
  else {
    count--;
    printf("Number poped from queue is %d\n", queue[front++]);
  }
}
void display() {
  int i;
  if (count == 0)
    printf("Empty");
  else
    for (i = front; i <= rear; i++)
      printf("%d\t ", queue[i]);
}
int size() { return count; }
void main() {
  int n, ch = 10;
  clrscr();
  while (ch != 5) {
    printf("select from the option\n");
    printf("1.Push || Enqueue\n");
    printf("2.Pop|| Dequeue\n");
    printf("3.SizeOfQueue\n");
    printf("4.Display\n");
    printf("5.EXIT\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1: {
      printf("What no. do you want to push in queue\n");
      scanf("%d", &n);
      push(n);
      break;
    }
    case 2: {
      pop();
 
      break;
    }
    case 3: {
      n = size();
      printf("Size of queue is %d\n", n);
      break;
    }
    case 4: {
      printf("Queue is \n ");
      display();
    }
    case 5:
      break;
    }
  }
  getch();
}
