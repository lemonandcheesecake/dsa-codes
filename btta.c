#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->item);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->item);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->item);
    }
}

struct node* createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item=value;
    newNode->left = NULL;
    newNode->right=NULL;
    return newNode;
}