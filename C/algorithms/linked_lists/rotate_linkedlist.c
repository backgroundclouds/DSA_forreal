// Algorithm: Rotate a Singly Linked List
// Time: O(n) | Space: O(1)
// Pattern: Connects the tail to the head to form a cycle, calculates the rotation offset using modulo math, and severs the cycle at the new tail.

#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int data;
    struct node* next;
}node;

node* initnode(int data){
    node *n = malloc(sizeof(node));
    if(n == NULL){
        printf("Memmory out\n");
        return NULL;
    }
    n->data = data;
    n->next=NULL;
    return n;
}

void appendlist(node **head, int data){
    node *n = initnode(data);
    if(*head == NULL){
        *head = n;
        return;
    }
    node *t = NULL;
    t = *head;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = n;
    return;
}

node* shift_list(node *head, int k){
    if(head == NULL ){
        return head;
    }
    int n = 1;  //1 based indexing?
    //traverse to tail and get n
    node *current = head;
    while(current->next != NULL){
        n++;
        current = current->next;
    }
    k = (k % n); //normalize
    if(k == 0){
        return head;
    }
    k = (k + n) % n; //off-set formula

    //connect head to tail, make list cyclical
    current->next = head;
    current = head; //reset current back to beginning of list

    //the rotation to start from whence the shift
    int r = n -k; //rotation
    for(int i = 1; i< n-k; i++){
        current = current->next;
    }
    head = current->next; //update
    current->next = NULL; //severe
    return head;
}


void display_list(node *head);

int main(){
    node *list = NULL;
    appendlist(&list, 1);
    appendlist(&list, 2);
    appendlist(&list,3);
    appendlist(&list,4);
    appendlist(&list,5);
    appendlist(&list,6);
    appendlist(&list,7);
    appendlist(&list,8);
    appendlist(&list,9);

    display_list(list);

    list = shift_list(list, 3);

    display_list(list);
    
    return 0;
}


void display_list(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
