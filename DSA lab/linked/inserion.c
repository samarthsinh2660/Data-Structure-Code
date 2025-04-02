#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to traverse and print the linked list
void traversal(struct node* ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List:\n");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the list
struct node* first(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}

// Function to insert a node at a specific index in the list
struct node* bet(struct node* head, int data, int index) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i = 0;
    while (i != index - 1) {
        if (p == NULL) {
            printf("Index out of bounds.\n");
            return head;
        }
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

    if (head == NULL) {
        ptr->next = NULL;
        ptr->data = data;
        return ptr;
    }

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
    if (prevnode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return head;
    }
    
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    
    return head;
}

// Function to search for an element in the linked list
void search(struct node* head, int key) {
    struct node* p = head;
    int i = 0;
    while (p != NULL) {
        if (p->data == key) {
            printf("Element %d found at index %d\n", key, i);
            return;
        }
        p = p->next;
        i++;
    }
    printf("Element %d not found in the list.\n", key);
}

int main() {
    struct node* head = NULL;
    int choice, data, index, key;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Traverse the list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at a specific index\n");
        printf("4. Insert at the end\n");
        printf("5. Insert after a given node (requires at least 1 element)\n");
        printf("6. Search for an element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traversal(head);
                break;
            case 2:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = first(head, data);
                break;
            case 3:
                printf("Enter the data to insert and index: ");
                scanf("%d %d", &data, &index);
                head = bet(head, data, index);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = end(head, data);
                break;
            case 5:
                if (head == NULL) {
                    printf("The list is empty. Cannot insert after a given node.\n");
                } else {
                    printf("Enter the data to insert after the first node: ");
                    scanf("%d", &data);
                    head = giv(head, head, data);  // Inserts after the first node
                }
                break;
            case 6:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
