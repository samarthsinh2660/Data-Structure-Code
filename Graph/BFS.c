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
    return q->r == q->size - 1;
}

// Function to check if the queue is empty
int isEmpty(struct queue *q) {
    return q->r == q->f;
}

// Function to add an element to the queue
void enqueue(struct queue *q, int data) {
    if (isFull(q)) {
        printf("The queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = data;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty, cannot dequeue\n");
        return -1;
    } else {
        q->f++;
        return q->arr[q->f];
    }
}

// Function to display all elements in the queue
void traversal(struct queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty, cannot print the queue\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->f + 1; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->r = q->f = -1;  // Initialize front and rear
    q->arr = (int *)malloc(q->size * sizeof(int));  // Allocate memory for the array

    int u;
    int i = 0;
    int visited[7] = {0};  // Visited array for BFS
    int a[7][7] = {        // Adjacency matrix representation of the graph
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    printf("%d\n", i);  // Print the starting node
    visited[i] = 1;
    enqueue(q, i);

    while (!isEmpty(q)) {
        int node = dequeue(q);
        printf("%d ", node);  // Print the current node

        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    return 0;
}
