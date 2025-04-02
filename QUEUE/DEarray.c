#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next, *prev;
};

// Global pointers for front and rear of the deque
struct node *f = NULL;
struct node *r = NULL;

// Function to create a new node
struct node *createnode(int val) {
    struct node *q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    q->data = val;
    q->next = NULL;
    q->prev = NULL;
    return q;
}

// Function to enqueue at the front
void enquef(int val) {
    struct node *newNode = createnode(val);

    if (f == NULL) { // If the deque is empty
        f = r = newNode;
    } else { // Insert at the front
        newNode->next = f;
        f->prev = newNode;
        f = newNode;
    }
    printf("Enqueued %d at the front\n", val);
}

// Function to enqueue at the rear
void enquer(int val) {
    struct node *newNode = createnode(val);

    if (r == NULL) { // If the deque is empty
        f = r = newNode;
    } else { // Insert at the rear
        r->next = newNode;
        newNode->prev = r;
        r = newNode;
    }
    printf("Enqueued %d at the rear\n", val);
}

// Function to dequeue from the front
void dequef() {
    if (f == NULL) { // If the deque is empty
        printf("Deque is empty, cannot dequeue from the front.\n");
        return;
    }

    struct node *temp = f;
    printf("Dequeued %d from the front\n", f->data);

    if (f == r) { // If there's only one element
        f = r = NULL;
    } else { // Remove the front element
        f = f->next;
        f->prev = NULL;
    }
    free(temp);
}

// Function to dequeue from the rear
void dequer() {
    if (r == NULL) { // If the deque is empty
        printf("Deque is empty, cannot dequeue from the rear.\n");
        return;
    }

    struct node *temp = r;
    printf("Dequeued %d from the rear\n", r->data);

    if (f == r) { // If there's only one element
        f = r = NULL;
    } else { // Remove the rear element
        r = r->prev;
        r->next = NULL;
    }
    free(temp);
}

// Function to display the deque
void display() {
    if (f == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct node *temp = f;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    enquef(10); // Enqueue 10 at the front
    enquef(20); // Enqueue 20 at the front
    enquer(30); // Enqueue 30 at the rear
    enquer(40); // Enqueue 40 at the rear

    display(); // Display the deque

    dequef(); // Dequeue from the front
    display(); // Display the deque

    dequer(); // Dequeue from the rear
    display(); // Display the deque

    dequef(); // Dequeue from the front
    dequer(); // Dequeue from the rear

    display(); // Display the deque after all operations

    return 0;
}
