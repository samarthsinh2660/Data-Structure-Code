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

struct node* search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if (root ->data > key){
        return search(root->left, key);
    }
    else{
        return search(root-> right, key);
    }
    
}

// without recursion
struct node* iterativesearch(struct node* root, int key){
 while(root != NULL){
    if(root->data == key){
        return root;
    }
    else if(root-> data > key){
        root = root->left;
    }
    else{
        root = root->right;
    }
 }  
 return NULL;
}

int main(){
    struct node* p = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("the inorder travelsal is:- ");
    inorder(p);

    printf("\n");
    struct node * n = search(p , 1);
    if(n!= NULL){
        printf("Element found %d", n->data);
    }
    else{
        printf("data not found");
    }

    printf("\n");
    struct node * n1 = iterativesearch(p , 1);
    if(n1!= NULL){
        printf("Element found %d", n->data);
    }
    else{
        printf("data not found");
    }
}