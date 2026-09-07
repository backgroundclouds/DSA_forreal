//Doubly datastructure, with basic innit, insert, and display function (utility)

#include <stdio.h>
#include <stdlib.h>
#define ADD_THESE {48, 100, 104, 200 }

typedef struct DoubleyNode{
    int value;
    struct DoubleyNode* next;
    struct DoubleyNode* prev;
    
}DoubleyNode;

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

int main(){
    DoubleyNode *head = NULL;

    int add_these[] = ADD_THESE;
    int n = sizeof(add_these)/sizeof(add_these[0]);
    for(int i =0; i < n; i++){
        append_dlist(&head, add_these[i]);
    }

    display_doublelist(head);
    return 0;
}
