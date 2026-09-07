//updates made to type return of remove_rear, remove_front // void is better for generalizing // can always update later 

#include <stdio.h>
#include <stdbool.h>

//enter shift
#define K 5
//enter test array
#define TEST_DATA {1, 2, 3, 4}

#define MAX 20

typedef struct {
    int *queue[MAX];
    int front;
    int rear;
} Deque;

void init(Deque *d);
bool is_full(Deque *d);
bool is_empty(Deque *c);
void add_rear(Deque *d, int *value);
void add_front(Deque *d, int *value);
void remove_front(Deque *d);
void remove_rear(Deque *d);
void display_deque(Deque *d);

void rotate_deque(Deque *d, int k){
    if (is_empty(d)){ 
    printf("deque is empty \n");
    return;
    }

    int count = (d->rear + MAX - d->front) % MAX +1; //circular distance formula 

    k = ((k%count)+count)%count; // k % size handles excess rotations // + size 5 size normalizes negative rotations into postives

    for (int i = 0; i < k; i++){
        //"peek" next element before dequeue
        int *item = d->queue[d->rear];
        //remove
        remove_rear(d);
        //shift
        add_front(d, item);
    }
    return;
}
int main(){
    Deque deque;
    init(&deque);

    int array[] = TEST_DATA;
    int n = sizeof(array)/sizeof(array[0]);
    for(int i =0; i< n; i++){
        if(n > MAX){
            printf("Test Array exceeds Deque capacity \n");
            return 1;
        }
        add_rear(&deque, &array[i]);
    }
    display_deque(&deque);

    int shift = K;
    rotate_deque(&deque, shift);
    printf("and %d ->", shift);

    display_deque(&deque);
    printf("\n");

    return 0;
}

void init(Deque *d){
    d->front=-1;
    d->rear=-1;
};

bool is_full(Deque *d){
    if((d->rear+1) % MAX == d->front){
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

void add_rear(Deque *d, int *value){
    if(is_full(d)){
        printf("Queue is full\n");
        return;
    }
    //iterate value
    d->rear= (d->rear+1) % MAX;
    d->queue[d->rear] = value;   
    //front only stays -1 when empty, otherwise updates
    if(d->front == -1){
        d->front = 0; //rear doesn't need to be updated, updates on its own above
    }
}

void add_front(Deque *d, int *value){
        if(is_full(d)){
        printf("Queue is full \n");
        return;
    }
    if(d->front ==-1) //when queue is empty, update both rear and front value
    {
        d->front = 0; //front value needs manual assignment for empty scenarios // mod math for iteration does not work for add_front and -1 as it does add_rear -1
        d->rear= 0;
        d->queue[d->front] = value;  
    }
    else{
    d->front = (d->front-1 + MAX) % MAX;
    d->queue[d->front] = value;
    }    
}

void remove_front(Deque *d){
    if(is_empty(d)){
        printf("Queue is empty \n");
        return;
    }
    else{
        int *dequeued = d->queue[d->front];
        //edge case queue only 1 left in array
        //remove and reset both values to empty
        if(d->front == d->rear){
            d->front =-1;
            d->rear = -1;
        }
        else{
            d->front = (d->front+1) % MAX;
        }
    return;
}
}

void remove_rear(Deque *d){

    if(is_empty(d)){
        printf("Queue is empty");
        return;
    }
    else{
        int *dequeued = d->queue[d->rear]; // get the current value\
        //special pop // only 1 item left
        if(d->front == d->rear){  //oldest entry and newest entry pointer are at the same place
        //reset to empty
        d->front =-1;
        d->rear = -1;
    }
        else{
        //pop as normal
            d->rear = (d->rear -1 + MAX) % MAX;
        }
        return;
    }
}

void display_deque(Deque *d){
    if(is_empty(d)){
        printf("The deque is currently empty.\n\n");
        return;
    }
    int count = (d->rear + MAX - d-> front) % MAX +1; 
    int current_index = d->front;
    printf("[");
    for (int i = 0; i < count; i++){
        printf("%d,", *(d->queue[current_index]));
        current_index = (current_index+1) % MAX;
    }
    printf("]");


    if(is_empty(d)){
        printf("The line is currently empty.\n\n");
        return;
    }
}