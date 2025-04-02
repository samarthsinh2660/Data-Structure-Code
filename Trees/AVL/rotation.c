#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createnode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int max (int a, int b){
    return a > b ? a : b;
}

int gethieght(struct node * n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

int getBF(struct node * n){
    if(n == NULL){
        return 0;
    }
    return gethieght(n->left) - gethieght(n->right);
}

struct node * rightrot(struct node *y){
    struct node * x = y-> left;
    struct node * t2 = x-> right; 

    x->right = y;
    y->left = t2;

    y->height = max(gethieght(y->left), gethieght(y->right)) + 1;
    x->height = max(gethieght(x->left), gethieght(x->right)) + 1;

    return x;
}

struct node * leftrot(struct node *x){
    struct node * y = x->right;
    struct node * t2 = y->left; 

    x->right = t2;
    y->left = x;

    y->height = max(gethieght(y->left), gethieght(y->right)) + 1;
    x->height = max(gethieght(x->left), gethieght(x->right)) + 1;

    return y;
}

struct node * insert(struct node * node, int key){
    // Step 1: Perform the normal BST insertion
    if(node == NULL){
        return createnode(key);
    }

    if(key < node->data){
        node->left = insert(node->left, key);
    }
    else if(key > node->data){
        node->right = insert(node->right, key);
    }
    else {
        // Duplicate keys are not allowed in BST
        return node;
    }

    // Step 2: Update height of this ancestor node
    node->height = 1 + max(gethieght(node->left), gethieght(node->right));

    // Step 3: Get the balance factor of this ancestor node to check whether this node became unbalanced
    int bf = getBF(node);

    // Left Left Case
    if (bf > 1 && key < node->left->data) {
        return rightrot(node);
    }

    // Right Right Case
    if (bf < -1 && key > node->right->data) {
        return leftrot(node);
    }

    // Left Right Case
    if (bf > 1 && key > node->left->data) {
        node->left = leftrot(node->left);
        return rightrot(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->data) {
        node->right = rightrot(node->right);
        return leftrot(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

void inorder(struct node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;
    root = insert(root, 45);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 9);

    printf("The inorder traversal is: ");
    inorder(root);

    return 0;
}
