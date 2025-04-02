#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct node {
    int data; 
    struct node *next;
};

// Declare front and rear as global pointers
struct node *f = NULL;     
struct node *r = NULL;

// Function to check if the queue is empty
int isEmpty() {
    if (f == NULL) {        // If front is NULL, the queue is empty
        return 1;          
    } else {
        return 0;       
    }
}

// Function to add an element to the queue
void enqueue(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));  
    if (ptr == NULL) {       // Check if memory allocation failed
        printf("Memory allocation failed. Can't add the value\n");
        return;
    }
    ptr->data = data;        
    ptr->next = NULL;      
    if (f == NULL) {         // If the queue is empty, new node is both front and rear
        f = r = ptr;
    } else {              
        r->next = ptr;
        r = ptr;
    }
}

// Function to remove an element from the queue
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
        printf("The queue is empty, cannot print the queue.\n");
    } else {
        struct node *temp = f; 
        printf("The elements in the queue are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Enqueue elements into the queue
    enqueue(10);  
    enqueue(20); 
    enqueue(30);   

    // Display the queue elements
    traversal();    

    // Dequeue an element and display it
    int d = dequeue();
    printf("The element which is dequeued is %d\n", d);

    // Display the queue elements after dequeue
    traversal();    

    return 0;
}
