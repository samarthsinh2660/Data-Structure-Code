#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traversal(struct node* ptr){
 while (ptr != NULL){
    
  printf("%d\n", ptr->data);
  ptr = ptr -> next;
 }
}

int main(){

   struct node* head = NULL;
   struct node* second= NULL;
   struct node* third = NULL;
   head = (struct node * ) malloc(sizeof(struct node));
   second = (struct node * ) malloc(sizeof(struct node));
    third = (struct node * ) malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    second->data = 10;
    second -> next = third;
    third -> data = 25;
    third->next = NULL;  

    traversal(head);


   

    return 0;
}