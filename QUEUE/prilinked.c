#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the priority queue
struct Node {
    int data;      // Value of the element
    int priority;  // Priority of the element
    struct Node *next;
};

struct Node* front = NULL;  // Declare the front pointer as a global variable

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the priority queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to add an element with a specific priority to the priority queue
void enqueue(int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (front == NULL || front->priority > priority) {
        // Insert at the beginning if the queue is empty or the new node has higher priority
        newNode->next = front;
        front = newNode;
    } else {
        // Find the correct position to insert the new node
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued: %d with priority %d\n", data, priority);
}

// Function to remove the element with the highest priority from the priority queue
int dequeue() {
    if (isEmpty()) {
        printf("The priority queue is empty, cannot dequeue.\n");
        return -1; // Return an error value
    }
    struct Node* temp = front;
    int data = temp->data;
    front = front->next;
    free(temp);
    return data;
}

// Function to remove a specific element from the priority queue
void dequeueElement(int data) {
    if (isEmpty()) {
        printf("The priority queue is empty, cannot dequeue specific element.\n");
        return;
    }
    
    struct Node* temp = front;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        front = temp->next;
        free(temp);
        printf("Dequeued specific element: %d\n", data);
        return;
    }

    // Search for the node to be deleted, keeping track of the previous node
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the element was not found
    if (temp == NULL) {
        printf("Element %d not found in the priority queue.\n", data);
        return;
    }

    // Unlink the node from the list and free it
    prev->next = temp->next;
    free(temp);
    printf("Dequeued specific element: %d\n", data);
}

// Function to display all elements in the priority queue
void traversal() {
    if (isEmpty()) {
        printf("The priority queue is empty, cannot print.\n");
        return;
    }
    printf("Priority Queue elements:\n");
    struct Node* temp = front;
    while (temp != NULL) {
        printf("Value: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    // Enqueue elements with specific priorities
    enqueue(10, 2);
    enqueue(5, 1);
    enqueue(20, 3);
    enqueue(15, 2);

    // Display the queue elements
    traversal();

    // Dequeue the element with the highest priority
    int highest = dequeue();
    printf("Dequeued element with the highest priority: %d\n", highest);

    // Display the queue elements after dequeue
    traversal();

    // Dequeue a specific element
    dequeueElement(15);
    
    // Display the queue elements after dequeuing a specific element
    traversal();

    return 0;
}
