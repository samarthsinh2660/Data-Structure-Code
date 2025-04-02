#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to traverse and print the list
struct node* trav(struct node* head) {
    struct node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return head;
}

// Function to add a node at the beginning
struct node* fir(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr->data = data;
    ptr->next = p;
    ptr->prev = NULL;
    p->prev = ptr;
    head = ptr;
    return head;
}

// Function to add a node in between
struct node* bet(struct node* head, int data, int index) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    p->next->prev = ptr;
    return head;
}

// Function to add a node at the end (tail)
struct node* tail(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    // Traverse to the end of the list
    while (p->next != NULL) {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;

    return head;
}

// Function to delete a node from the head
struct node* delHead(struct node* head) {
    struct node* temp = head;
    head = head->next;
    if (head != NULL) {  // If the list has more than one node
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from between
struct node* delBet(struct node* head, int index) {
    struct node* p = head;
    int i = 0;

    // Traverse to the node before the node to be deleted
    while (i != index - 1) {
        p = p->next;
        i++;
    }

    struct node* temp = p->next;  // Node to be deleted
    p->next = temp->next;
    if (temp->next != NULL) {  // If it is not the last node
        temp->next->prev = p;
    }
    free(temp);
    return head;
}

// Function to delete the last node
struct node* delTail(struct node* head) {
    struct node* p = head;

    // Traverse to the last node
    while (p->next != NULL) {
        p = p->next;
    }

    struct node* temp = p;
    p = p->prev;
    if (p != NULL) {
        p->next = NULL;
    } else {  // If there was only one element in the list
        head = NULL;
    }
    free(temp);
    return head;
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;
    second->data = 10;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->data = 25;
    third->next = NULL;

    printf("Original list:\n");
    trav(head);

    printf("List after adding 5 at the beginning:\n");
    head = fir(head, 5);
    trav(head);

    printf("List after adding 50 at index 1:\n");
    head = bet(head, 50, 1);
    trav(head);

    printf("List after adding 100 at the end:\n");
    head = tail(head, 100);
    trav(head);

    printf("List after deleting the head:\n");
    head = delHead(head);
    trav(head);

    printf("List after deleting node at index 1:\n");
    head = delBet(head, 1);
    trav(head);

    printf("List after deleting the last node:\n");
    head = delTail(head);
    trav(head);

    return 0;
}
