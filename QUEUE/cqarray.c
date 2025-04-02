#include <stdio.h>
#include <stdlib.h>

// Define the circular queue structure
struct cirqueue {
    int data;   
    int size;   
    int f;     
    int r;       
    int *arr;    
};

// Function to check if the queue is full
int isFull(struct cirqueue *q) {
    // Queue is full if incrementing rear by 1 makes it equal to front
    if ((q->r + 1) % q->size == q->f) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(struct cirqueue *q) {
    // Queue is empty if front and rear are the same
    if (q->r == q->f) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(struct cirqueue *q, int data) {
    if (isFull(q)) {
        printf("The queue is full\n");
    } else {
        q->r = (q->r + 1) % q->size;  // Circular increment of rear index
        q->arr[q->r] = data; 
    }
}

// Function to remove an element from the queue
int dequeue(struct cirqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty, cannot dequeue\n");
        return -1;  // Return an error value
    } else {
        q->f = (q->f + 1) % q->size;  // Circular increment of front index
        int val = q->arr[q->f]; 
        return val; 
    }
}

// Function to display all elements in the queue
void traversal(struct cirqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty, cannot print the queue\n");
    } else {
        printf("Queue elements: ");
        int i = (q->f + 1) % q->size;  // Start from the element after front
        while (i != (q->r + 1) % q->size) {  
            printf("%d ", q->arr[i]);  
            i = (i + 1) % q->size;  // Circular increment
        }
        printf("\n");
    }
}

int main() {
   
    struct cirqueue *q = (struct cirqueue *)malloc(sizeof(struct cirqueue));
    q->size = 5; 
    q->r = q->f = 0;  
    q->arr = (int *)malloc(q->size * sizeof(int));  
    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Display the queue elements
    traversal(q);

    // Dequeue an element from the queue
    int d = dequeue(q);
    printf("The value that has been dequeued is %d\n", d);

    // Display the queue elements after dequeue
    traversal(q);

    // Enqueue more elements to check circular behavior
    enqueue(q, 40);
    enqueue(q, 50);
    traversal(q);  // Display the queue elements

    return 0;
}
