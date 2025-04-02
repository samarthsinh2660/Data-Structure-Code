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

void inorder(struct node* root){
    if (root == NULL) {
        printf("The tree is empty ");
        return;  
    }

    if (root->left != NULL) {
        inorder(root->left);
    }
    
    printf("%d ", root->data);

    if (root->right != NULL) {
        inorder(root->right);
    }
}

struct node* inorderpre(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}


int main(){
    struct node* p = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);

    /* Tree structure:
            5
           / \
          3   6
         / \
        1   4 
    */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("The inorder traversal is: ");
    inorder(p);

    printf("\n");
    delete(p, 3);

    printf("The inorder traversal after delete is: ");
    inorder(p);

    return 0;
}
