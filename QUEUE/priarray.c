#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Priority Queue
struct priorityQueue {
    int size;     // Maximum size of the priority queue
    int count;    // Current number of elements in the queue
    int *arr;     // Pointer to the array storing queue elements
};

// Function to check if the priority queue is full
int isFull(struct priorityQueue *q) {
    return (q->count == q->size);  // Queue is full if count equals size
}

// Function to check if the priority queue is empty
int isEmpty(struct priorityQueue *q) {
    return (q->count == 0);  // Queue is empty if count is 0
}

// Function to add an element to the priority queue
void enqueue(struct priorityQueue *q, int data) {
    if (isFull(q)) {
        printf("The priority queue is full, cannot enqueue.\n");
        return;
    }

    // Insert the new element at the end
    int i = q->count - 1;
    while (i >= 0 && q->arr[i] > data) {  // Shift elements to maintain sorted order
        q->arr[i + 1] = q->arr[i];
        i--;
    }

    // Insert the new element
    q->arr[i + 1] = data;
    q->count++;
}

// Function to remove the element with the highest priority (smallest value)
int dequeue(struct priorityQueue *q) {
    if (isEmpty(q)) {
        printf("The priority queue is empty, cannot dequeue.\n");
        return -1;  // Return an error value
    }

    int highestPriority = q->arr[0];  // Element with the highest priority
    // Shift elements to the left
    for (int i = 0; i < q->count - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }

    q->count--;  // Decrease the count
    return highestPriority;  // Return the dequeued element
}

// Function to display all elements in the priority queue
void traversal(struct priorityQueue *q) {
    if (isEmpty(q)) {
        printf("The priority queue is empty, cannot print.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Function to return the element with the highest priority without removing it
int peek(struct priorityQueue *q) {
    if (isEmpty(q)) {
        printf("The priority queue is empty, cannot peek.\n");
        return -1;  // Return an error value
    }
    return q->arr[0];  // Return the element with the highest priority
}

// Main function
int main() {
    struct priorityQueue *q = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));  // Allocate memory for the queue
    q->size = 100;  // Set the maximum size of the queue
    q->count = 0;  // Initialize the count of elements
    q->arr = (int *)malloc(q->size * sizeof(int));  // Allocate memory for the array

    // Enqueue elements
    enqueue(q, 30);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 5);

    // Display the queue elements
    traversal(q);

    // Peek at the element with the highest priority
    int highest = peek(q);
    printf("Element with the highest priority: %d\n", highest);

    // Dequeue elements
    int d = dequeue(q);
    printf("The value that has been dequeued is %d\n", d);

    // Display the queue elements after dequeue
    traversal(q);

    return 0;
}
