#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *ptr, *new_node;

struct node *start = NULL;
struct node *insert(struct node *, int);

struct node *insert(struct node *start, int val) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (start == NULL) {
        start=new_node;
    }
    else {
        ptr=start;
        while (ptr->next != NULL)
            ptr= ptr->next;
        ptr->next = new_node;
    }
    return start;
}