#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q) {
    if (q->r == q->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct queue *q) {
    if (q->r == q->f) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct queue *q, int data) {
    if (isFull(q)) {
        printf("The queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, can't dequeue\n");
        return -1;
    } else {
        q->f++;
        return q->arr[q->f];
    }
}

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

int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->r = q->f = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int choice, data, val;

    do {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                val = dequeue(q);
                if (val != -1) {
                    printf("The value dequeued is %d\n", val);
                }
                break;
            case 3:
                traversal(q);
                break;
            case 4:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
