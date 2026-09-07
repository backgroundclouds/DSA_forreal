// Data Structure: Deque (Double-Ended Circular Queue)
// Mechanics: Allows insertion and deletion at both the front and rear using modulo wrapping.

#include <stdio.h>
#include <stdbool.h>

#define DEQUE_SIZE 6

typedef struct {
    char* queue[DEQUE_SIZE];
    int front;
    int rear;
} Deque;

// --- Prototypes ---
void init(Deque *d);
bool is_full(Deque *d);
bool is_empty(Deque *d);
void add_rear(Deque *d, char* value);
void add_front(Deque *d, char* value);
char* remove_front(Deque *d);
char* remove_rear(Deque *d);
void display_deque(Deque *d);


int main(){
    Deque deque;
    init(&deque);

    //debug starting values
    printf("starting values \n");
    printf("Debug : rear = [%d] \n", deque.rear);
    printf("Debug : front = [%d] \n\n", deque.front);

    char *a = "red";
    char *b = "blue";
    char *c = "green";
    char *d = "purple";
    char *e = "silver";
    char *f = "gold";

    display_deque(&deque);

    add_front(&deque, a);
    add_front(&deque, b);
    add_front(&deque, c);
    add_front(&deque, d);
    add_front(&deque, e);
    add_front(&deque, f);

    display_deque(&deque);
    
    printf("\nTesting removals:\n");
    printf("Popped front: %s\n", remove_front(&deque));
    printf("Popped rear: %s\n\n", remove_rear(&deque));
    
    display_deque(&deque);

    return 0;
}

// --- Utility Implementations ---
void init(Deque *d){
    d->front = -1;
    d->rear = -1;
}

bool is_full(Deque *d){
    if((d->rear+1) % DEQUE_SIZE == d->front){
        return true;
    }
    return false;
}

bool is_empty(Deque *c){
    if(c->front == -1){
        return true;
    }
    return false;
}

void add_rear(Deque *d, char* value){
    if(is_full(d)){
        printf("Queue is full\n");
        return;
    }
    //iterate value
    d->rear= (d->rear+1) % DEQUE_SIZE;
    d->queue[d->rear] = value;    
    //front only stays -1 when empty, otherwise updates
    if(d->front == -1){
        d->front = 0; //rear doesn't need to be updated, updates on its own above
    }
}

void add_front(Deque *d, char* value){
    if(is_full(d)){
        printf("Queue is full \n");
        return;
    }
    if(d->front == -1) //when queue is empty, update both rear and front value
    {
        d->front = 0; //front value needs manual assignment for empty scenarios
        d->rear= 0;
        d->queue[d->front] = value;  
    }
    else{
        d->front = (d->front-1 + DEQUE_SIZE) % DEQUE_SIZE;
        d->queue[d->front] = value;
    }    
}

char* remove_front(Deque *d){
    if(is_empty(d)){
        printf("Queue is empty \n");
        return NULL;
    }
    else{
        char* dequeued = d->queue[d->front];
        //edge case queue only 1 left in array
        //remove and reset both values to empty
        if(d->front == d->rear){
            d->front =-1;
            d->rear = -1;
        }
        else{
            d->front = (d->front+1) % DEQUE_SIZE;
        }
        return dequeued;
    }
}

char* remove_rear(Deque *d){
    if(is_empty(d)){
        printf("Queue is empty\n");
        return NULL;
    }
    else{
        char * dequeued = d->queue[d->rear]; // get the current value
        //special pop // only 1 item left
        if(d->front == d->rear){  //oldest entry and newest entry pointer are at the same place
            //reset to empty
            d->front =-1;
            d->rear = -1;
        }
        else{
            //pop as normal
            d->rear = (d->rear -1 + DEQUE_SIZE) % DEQUE_SIZE;
        }
        return dequeued;
    }
}

void display_deque(Deque *d){
    if(is_empty(d)){
        printf("The deque is currently empty.\n\n");
        return;
    }
    int count = (d->rear + DEQUE_SIZE - d-> front) % DEQUE_SIZE +1; 
    int current_index = d->front;
    printf("Count in deque is currently %d \n", count);
    printf("FIFO \n");
    for (int i = 0; i < count; i++){
        printf("[%d] : [%s] \n", i+1, d->queue[current_index]);
        current_index = (current_index+1) % DEQUE_SIZE;
    }
}