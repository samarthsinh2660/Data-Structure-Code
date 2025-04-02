#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int data;
    int size;
    int f;  // Front index
    int r;  // Rear index
    int *arr;
};

// Function to check if the queue is full
int isFull(struct queue *q) {
    if (q->r == q->size - 1) {  // Corrected comparison operator
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(struct queue *q) {
    if (q->r == q->f) {  // Queue is empty if front and rear are the same
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(struct queue *q, int data) {
    if (isFull(q)) {
        printf("The queue is full\n");
    } else {
        q->r++;  // Increment rear index
        q->arr[q->r] = data;  // Add element to the queue
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is full cant dequeue\n");
    }
    else{
        q->f++;
        int val = q->arr[q->f];
        return val;
    }
}

// Function to display all elements in the queue
void traversal(struct queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty, cannot print the queue\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->f + 1; i <= q->r; i++) {  // Traverse from front+1 to rear
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));  // Allocate memory for the queue
    q->size = 100;
    q->r = q->f = -1;  // Initialize front and rear
    q->arr = (int *)malloc(q->size * sizeof(int));  // Allocate memory for the array

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Display the queue elements
    traversal(q); 

    // dequeue of queue
    int d = dequeue(q);
    printf("the vaue that has de queue is %d\n", d);


    return 0;
}
