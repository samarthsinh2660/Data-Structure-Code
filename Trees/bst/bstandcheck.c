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

int isBST(struct node* root){
    static struct node * prev = NULL;
    if(root != NULL){
        if(!isBST(root-> left)){
            return 0;
        }
        if(prev != NULL && root-> data <= prev-> data){
            return  0;
        }
        prev = root;
        return(isBST(root->right));
    }
    else{
        return 1;
    }
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
    // isbst = 1 then is bst or =0 not bst
    if(isBST(p)){
        printf("it is BST");
    }
    else{
        printf("It is not BST");
    }

}