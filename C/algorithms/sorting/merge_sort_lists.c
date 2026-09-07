// Standard merge of two sorted linked lists using a dummy node.

#include <stdio.h>
#include <stdlib.h>

typedef struct Linknode{
    int value;
    struct Linknode *next;
}Linknode;

Linknode* split_list(Linknode* head){
    Linknode *fast = head;
    Linknode *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if(fast != NULL){
            slow = slow->next;
        }
    }
    Linknode *temp = slow->next;
    slow->next = NULL;
    return temp;
}

Linknode* mergesort_lists(Linknode *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //split
    Linknode *secondN = split_list(head);

    //recursion
    Linknode* firstN = mergesort_lists(head); //implicit rename
    secondN = mergesort_lists(secondN);
    return merge_lists(firstN, secondN);
}


//original merge_lists
Linknode* merge_lists(Linknode *firstN, Linknode *secondN){
    if(firstN == NULL)
        return firstN;
    if(secondN ==NULL)
        return secondN;
    
    Linknode dummy; //dummy is a static node that holds the place of head for the new list
    dummy.next = NULL; 
    Linknode *tail = &dummy; //tail is traversal pointer for the new list

    while(firstN!= NULL && secondN!= NULL){
        if(firstN->value < secondN->value){ //
            tail->next = firstN;
            firstN = firstN->next;
            tail = tail->next;
        }
        else{
            tail->next = secondN;
            secondN = secondN->next;
            tail=tail->next;
        }
    }
    if(firstN != NULL){
        tail->next= firstN;
    }
    else{
        tail->next = secondN;
    }
}
