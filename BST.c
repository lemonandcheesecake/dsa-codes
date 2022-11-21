#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int data)
{
    struct node *newnode; 
    newnode = (struct node *) malloc(sizeof(struct node)); 
    newnode->data = data; 
    newnode->left = NULL; 
    newnode->right = NULL; 
    return newnode; 
}
 
void preOrder(struct  node* root)
{
    if(root!=NULL)
	{
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
void postOrder(struct  node* root)
{
    if(root!=NULL)
	{
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
 
void inOrder(struct  node* root)
{
    if(root!=NULL)
	{
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
    }
}

struct node *minValueNode(struct node *root) {
  struct node *current = root;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;
   printf("Smallest ---%d\n",current->data);
  return current;
}
struct node * search(struct node* root, int key)
{
    while(root!=NULL)
	{
	if(key == root->data)
	    return root;
	
	else if(key<root->data)
	    root = root->left;
	
	else
	    root = root->right;
	}
    return NULL;
}

void insert(struct node *root, int key)
{
    struct node *neew,*prev = NULL;
    while(root!=NULL)
	{
	prev = root;
	if(key==root->data)
	{
	    printf("Cannot insert %d, already in BST", key);
	    return;
	}
	else if(key<root->data)
	    root = root->left;
	else
	    root = root->right;
    }
    neew = createNode(key);
    if(key<prev->data)
		prev->left = neew;
    else
		prev->right = neew;
}

struct node *inOrderPredecessor(struct node* root)
{
    root = root->left;
    while (root->right!=NULL)
		root = root->right;
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node* iPre;
    if (root == NULL)
		return NULL;
    if (root->left==NULL&&root->right==NULL)
	{
	free(root);
	return NULL;
    }
    if (value < root->data)
		root-> left = deleteNode(root->left,value);
    else if (value > root->data)
		root-> right = deleteNode(root->right,value);
    else
	{
	iPre = inOrderPredecessor(root);
	root->data = iPre->data;
	root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

void main()
{
    struct node *p=createNode(50);
    struct node *p1=createNode(30);
    struct node *p2=createNode(70);
    struct node *p3=createNode(20);
    struct node *p4=createNode(40);
    struct node *p5=createNode(60);
    struct node *p6=createNode(80);
    clrscr();
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    printf("The inorder is\n");
    inOrder(p);
    printf("The preorder is \n");
    preOrder(p);
    printf("The postorder is \n");
    postOrder(p);
    printf("\n");
    printf("The impact of deletion is\n");
    deleteNode(p, 50);
    inOrder(p);
	printf("\n The minimum value is \n");
	minValueNode(p);
	getch();
}
