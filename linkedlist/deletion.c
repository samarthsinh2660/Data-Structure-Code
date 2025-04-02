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

struct node * fir(struct node * head){
   struct node* ptr = head; 
   head = head-> next;
   free(ptr);
   return head;
}

struct node * bet (struct node * head, int index){
   struct node* p = head;
   int i = 0; 
   while(i != index-1){
         p = p-> next;
         i++;
   }
   struct node* q  = p-> next;
   p-> next = q->next;
   free(q);
   return head;
}

struct node * end (struct node * head){
   struct node* p = head;
   struct node*q = head-> next; 
   while(q -> next != NULL){
         q = q-> next;
         p = p-> next;
   }
   free(q);
   p-> next = NULL;
   return head;
}

struct node * giv (struct node * head, int data){
   struct node* p = head;
   struct node*q = head-> next; 
   while(q -> data != data && q-> next != NULL){
         q = q-> next;
         p = p-> next;
   }
   if(q-> data == data){
   p-> next = q->next;
   free(q);
   }
   return head;
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
 /*    head  = fir(head);
    traversal(head); */


  /*   head = bet(head,1);
    traversal(head); */


/*     head = end(head);
   traversal(head); */

   head = giv(head, 10);
   traversal(head);

    return 0;
}