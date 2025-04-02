#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to traverse and print the linked list
void traversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning of the list
struct node* first(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Function to insert a node at a specific index in the list
struct node* bet(struct node* head, int data, int index) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}

// Function to insert a node at the end of the list
struct node* end(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    ptr->data = data;
    return head;
}

// Function to insert a node after a given node
struct node* giv(struct node* head, struct node* prevnode, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (prevnode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return head;
    }
    
    
    ptr->data = data;
    ptr->next = prevnode->next;  // Corrected to point to the next node of prevnode
    prevnode->next = ptr;        // Link previous node to new node
    
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    // Allocate memory for nodes in the linked list
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Initialize data and set up links
    head->data = 7;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 25;
    third->next = NULL;

    // Traverse and display the initial linked list
    printf("Initial Linked List:\n");
    traversal(head);

    // Insert at the beginning
    // head = first(head, 56);
    // traversal(head);

    // Insert at index 2
    // head = bet(head, 66, 2);
    // traversal(head);
 
    // Insert at the end
    // head = end(head, 70);
    // traversal(head);

    // Insert after a given node (second node)
    head = giv(head, second, 22);
    printf("\nLinked List after inserting 22 after the second node:\n");
    traversal(head);


    return 0;
}
