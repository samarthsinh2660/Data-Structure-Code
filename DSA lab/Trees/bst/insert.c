#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node * right;
};

struct node* createnode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node* root){
    if (root == NULL) {
        printf("The tree is empty\n");
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

// Modified insert function that doesn't use struct node**
void insert(struct node* root, int key){
    struct node* prev = NULL;
    struct node* current = root;

    if (root == NULL) {
        printf("Cannot insert into an empty tree. Root is NULL.\n");
        return;
    }
    
    // Traverse to find the correct insertion point
    while (current != NULL) {
        prev = current;
        if (current->data == key) {
            printf("Cannot insert the value, it already exists.\n");
            return;
        }
        else if (current->data > key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    // Create new node
    struct node* new = createnode(key);

    // Insert the new node in the appropriate place
    if (key < prev->data) {
        prev->left = new;
    } else {
        prev->right = new;
    }
}

int main() {
    struct node* root = NULL;
    int choice, key;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a value\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &key);
                if (root == NULL) {
                    root = createnode(key); // If root is NULL, create the root node
                } else {
                    insert(root, key);  // Insert into the tree
                }
                break;

            case 2:
                printf("The inorder traversal is: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
