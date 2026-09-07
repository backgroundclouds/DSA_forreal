// Doubly Linked List: In-Place Reversal
// Reverse Time: O(n) | Space: O(1)
// Reverses a doubly linked list by walking the nodes and swapping 
// the 'next' and 'prev' pointers at each step.

#include <stdio.h>
#include <stdlib.h>

#define ADD_THESE {10, 14, 18, 22, 26}

//Datastructure
typedef struct DoubleyNode{
    int value;
    struct DoubleyNode* next;
    struct DoubleyNode* prev;
    
}DoubleyNode;

//Utility Datastructure Prototypes
DoubleyNode* create_double(DoubleyNode *prev, int value);
void append_dlist(DoubleyNode **head, int value);
void display_doublelist(DoubleyNode *head);

//Algorithm
void reverse_doubley(DoubleyNode **head){
    if(*head == NULL || (*head)->next==NULL){
        return;
    }
    DoubleyNode *current_node = *head;
    DoubleyNode *prev_node = NULL;

    while(current_node !=NULL){
        //swap
        prev_node = current_node->prev;
        current_node->prev = current_node->next; //
        current_node->next = prev_node; //

        //update
        current_node = current_node->prev; //
    }
    if(prev_node != NULL){
        *head = prev_node->prev;
    };
    return;
}

//Implementation
int main(){
    DoubleyNode *head = NULL;

    int add_these[] = ADD_THESE;
    int n = sizeof(add_these)/sizeof(add_these[0]);
    for(int i =0; i < n; i++){
        append_dlist(&head, add_these[i]);
    }

    display_doublelist(head);
    printf("Reverse the doubley list \n");
    reverse_doubley(&head);
    display_doublelist(head);
    return 0;
}

DoubleyNode* create_double(DoubleyNode *prev, int value){
    DoubleyNode *doubley = malloc(sizeof(DoubleyNode));
    if( doubley == NULL){
        printf("No memmory!!!!!!!! \n");
        return NULL;
    }
    doubley->value = value;

    doubley->prev = prev;
    doubley->next= NULL;
    return doubley;
}

void append_dlist(DoubleyNode **head, int value){
    DoubleyNode *n = create_double(NULL, value); // creates a unique node, prev value NULL for now
    if(*head == NULL ){
        *head = n;
        return;
    }
    DoubleyNode *temp = *head;
    while(temp->next != NULL){
        temp = temp->next; //find the last node
    }
    temp->next = n; //assigns n to the next null in the list
    n->prev = temp; //connects n's prev bilaterally to the existing list
    return;
}
void display_doublelist(DoubleyNode *head){
    DoubleyNode *temp = head;
    int count = 0;
    while(temp != NULL){
        printf("%d \n", temp->value);
        // count++;
        temp = temp->next;
    }
    // printf("count is : %d \n", count);
    return;
}