// Algorithm: Linked List Union (Distinct Elements)
// Take two linked lists and return a new linked list containing all distinct elements from both lists
// Time: O(V^2) | Space: O(V)
// Pattern: Merges lists while running a nested boolean check on the new list to ensure only distinct, unvisited values are added.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//enter values for list 1 and 2
#define LIST_ONE { 2, 10, 5, 3, 4 }
#define LIST_TWO { 4,7,8,3,11 }

typedef struct Linknode{
    int value;
    struct Linknode *next;
}Linknode;

// --- Prototypes ---
Linknode* createlink(int value);
void appendlist(Linknode **head, int value_toadd);
void displaylist(Linknode *head);

// --- Core Algorithm ---
//returns true, if value is not used yet in list
bool value_available(int value, Linknode *list_head){
    if(list_head == NULL){
        return true;
    }
    Linknode *temp = list_head;

    while(temp != NULL){
        if(temp->value == value) {
            return false; // value was found, spot not available
        }
        temp=temp->next;
    }
    return true; // no value found, spot available
}

//problem solving stuff
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

//this version of merge, accounts for duplicates that may exist between both lists
Linknode* union_merge(Linknode *first, Linknode *second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    Linknode dummy;
    dummy.next= NULL;
    Linknode *tail = &dummy;
    while (first != NULL){
        //if next value of the list, is not in current list add it to current list 
        //can &dummy be passed like so as a paramter // or should i pass copy of list head
        Linknode *copy = dummy.next; 
        if (value_available(first->value, copy)){
            tail->next = first; //assign node from first list to newlist current tail
            first = first->next; //iterate first list forward
            tail = tail->next; //iterate tail traversal forward to end of list
            tail->next = NULL; //test

        }
        else{ //if value is already in current list
            Linknode *temp = first;
            first = first->next;
            free(temp);
        }
    }
    while (second != NULL){
        Linknode *copy = dummy.next; 
        if (value_available(second->value, copy)){
            tail->next = second; //assign node from second list to newlist current tail
            second = second->next; //iterate first list forward
            tail = tail->next; //iterate tail traversal forward to end of list
            tail->next = NULL; //test
        }
        else{ //if value is already in current list
            Linknode *temp = second;
            second = second->next;
            free(temp);
        }
    }
    tail->next = NULL;
    return dummy.next;
}

//renamed mergesort_lists
Linknode* mergesort_lists(Linknode *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //split
    Linknode *b = split_list(head);
    //rename
    Linknode *a =  head;

    //recursion
    a = mergesort_lists(a);
    b = mergesort_lists(b);
    return union_merge(a, b);
}

//unionfind
void unionfind(Linknode *head1, Linknode *head2){
    //connect lists
    Linknode *temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    //rename
    Linknode *superlist = head1;
    Linknode *list = mergesort_lists(superlist);
    displaylist(list);
    return;

}

int main(){

    Linknode *head1 = NULL;
    Linknode *head2 = NULL;
    int set_one[] = LIST_ONE; 
    int set_two[] = LIST_TWO;
    int n1 = sizeof(set_one)/sizeof(set_one[0]);
    int n2 = sizeof(set_two)/sizeof(set_two[0]);

    for(int i =0; i < n1; i++){
        appendlist(&head1, set_one[i]);
    }
    for(int i =0; i< n2; i++){
        appendlist(&head2, set_two[i]);
    }

    printf("Thus be the list of list one \n");
    displaylist(head1);
    printf("Thus be list two, yonder below \n");
    displaylist(head2);

    printf("Union Test \n");
    unionfind(head1, head2);

    return 0;
}

//////// Linked List Utility Stuff

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