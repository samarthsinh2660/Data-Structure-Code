#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node * right;
};

struct node* createnode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n-> data = data;
    n-> left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node* root){
    if (root == NULL) {
        printf("The tree is empty ");
        return;  
    }

    printf("%d ", root->data);
    if (root->left != NULL) {
        preorder(root->left);
    }
    if (root->right != NULL) {
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root == NULL) {
        printf("The tree is empty ");
        return;  
    }

    if (root->left != NULL) {
        postorder(root->left);
    }
    if (root->right != NULL) {
        postorder(root->right);
    }
    
    printf("%d ", root->data);
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

int main(){
    struct node* p = createnode(4);
    struct node* p1 = createnode(1);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(5);
    struct node* p4 = createnode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
     
    printf("the preorder travelsal is:- ");
    preorder(p);

    printf("\n");
    
    printf("the postorder travelsal is:- ");
    postorder(p);

    printf("\n");
    
    printf("the inorder travelsal is:- ");
    inorder(p);

}