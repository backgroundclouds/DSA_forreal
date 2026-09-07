#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Linknode{
    int value;
    struct Linknode *next;
}Linknode;


Linknode* createlink(int value){
    Linknode *linknode = malloc(sizeof(Linknode));
    if( linknode == NULL){
        printf("not enough memmory \n"); //safety
        return NULL;
    }
    linknode->value = value;
    linknode->next= NULL;
    return linknode;
}

void appendlist(Linknode **head, int value_toadd){
    Linknode *n = createlink(value_toadd);

    if(*head == NULL){ // if list is empty return 1 node 
        *head = n;
        return;
    }
    Linknode *temp = *head; //traversal node
    while(temp->next != NULL ){ //traverse to the end of the list
        temp = temp->next;
    }
    temp->next = n; //append
    return;
}


void displaylist(Linknode *head){
    Linknode *temp = head;
    int count = 0;
    while(temp->next != NULL){
        printf("%d \n",temp->value);
        // count++;
        temp = temp->next;
    }
    printf("%d \n",temp->value);
    // printf("count is : %d \n", count);
    return;
}


int main(){



    return 0;
}