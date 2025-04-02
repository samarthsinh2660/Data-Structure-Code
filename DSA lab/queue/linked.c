#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

int isEmpty() {
    if(f == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed. Can't add the value\n");
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (f == NULL) {
        f = r = ptr;
    } else {
        r->next = ptr;
        r = ptr;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("The queue is empty, cannot dequeue.\n");
        return -1;
    } else {
        struct node *ptr = f;
        f = f->next;
        int val = ptr->data;
        free(ptr);
        if (f == NULL) {
            r = NULL;
        }
        return val;
    }
}

void traversal() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
    } else {
        struct node *temp = f;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if (val != -1) {
                    printf("Dequeued element: %d\n", val);
                }
                break;
            case 3:
                traversal();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (choice != 4);

    return 0;
}
