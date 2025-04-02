#include <stdio.h>
#include <stdlib.h>  // Use stdlib.h instead of malloc.h for better portability

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {

        struct node *p;
    p= (struct node *)malloc(sizeof(struct node));
    p->data = 10;
    p->left = NULL;
    p->right = NULL;

    // Create the root node
    struct node* root = createNode(10);
    
    // Create other nodes and attach them
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);


/*      or best and good 
    struct node *p  = createnode(10);
     struct node *p1 = createnode(20);
     struct node * p2 = createnode(30);

    p->left = p1;
    p->right = p2; */
/* 
    Now the tree structure is:
           10
          /  \
        20    30
       /  \  /  \
      40  50 60  70 */
    
    return 0;
}
