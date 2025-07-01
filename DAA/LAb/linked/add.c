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
struct node* reverseList(struct node* head) {
    struct node* NewHead = NULL;
    while (head != NULL) {
        struct node* Next = head->next;
        head->next = NewHead;
        NewHead = head;
        head = Next;
    }
    return NewHead;
}
struct node* add(struct node* n1, struct node* n2) {
    struct node* dummy = (struct node*)malloc(sizeof(struct node));
    struct node* temp = dummy;
    int carry = 0;

    while (n1 != NULL || n2 != NULL || carry != 0) {
        int sum = 0;
        
        if (n1 != NULL) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            sum += n2->data;
            n2 = n2->next;
        }
         sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
     

        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = sum;
        n->next = NULL;

        temp->next = n;
        temp = temp->next;
    }

    return dummy->next;
}


int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    int data, n, i;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the first linked list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        head1 = first(head1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the second linked list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        head2 = first(head2, data);
    }
    traversal(head1);
    traversal(head2);

    head3 = add(head1, head2);
    head3 = reverseList(head3);
    
    printf("The sum of the two linked lists is:\n");
    traversal(head3);

    return 0;
}
