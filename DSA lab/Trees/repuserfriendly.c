#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
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

// Function to create a binary tree interactively
struct node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    // If the user enters -1, no node is created
    if (data == -1) {
        return NULL;
    }

    // Create the current node
    struct node* newNode = createNode(data);

    // Ask user if they want to create a left child
    char choice;
    printf("Do you want to add a left child for %d? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        newNode->left = createTree();
    } else {
        newNode->left = NULL;
    }

    // Ask user if they want to create a right child
    printf("Do you want to add a right child for %d? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        newNode->right = createTree();
    } else {
        newNode->right = NULL;
    }

    return newNode;
}

int main() {
    printf("Create your binary tree:\n");
    struct node* root = createTree();

    return 0;
}
