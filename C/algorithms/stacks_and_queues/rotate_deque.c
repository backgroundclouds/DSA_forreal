// Algorithm: Rotate Deque
// Time: O(k) (k = number of shifts) | Space: O(1)
// Pattern: Uses modulo arithmetic to calculate the exact rotation offset, 
// then shifts elements from rear to front in-place.

#include <stdio.h>
#include <stdbool.h>

#define K 5
#define TEST_DATA {1, 2, 3, 4}
#define MAX 20

typedef struct {
    int *queue[MAX];
    int front;
    int rear;
} Deque;

// --- Prototypes ---
void init(Deque *d);
bool is_full(Deque *d);
bool is_empty(Deque *c);
void add_rear(Deque *d, int *value);
void add_front(Deque *d, int *value);
void remove_front(Deque *d);
void remove_rear(Deque *d);
void display_deque(Deque *d);

// --- Core Algorithm ---
void rotate_deque(Deque *d, int k){
    if (is_empty(d)){ 
        printf("deque is empty \n");
        return;
    }

    int count = (d->rear + MAX - d->front) % MAX + 1; //circular distance formula 
    k = ((k % count) + count) % count; // normalizes negative rotations into postives

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

// --- Test Execution ---
int main(){
    Deque deque;
    init(&deque);

    int array[] = TEST_DATA;
    int n = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < n; i++){
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

// --- Utility Implementations ---
void init(Deque *d){
    d->front = -1;
    d->rear = -1;
}

bool is_full(Deque *d){
    return (d->rear + 1) % MAX == d->front;
}

bool is_empty(Deque *c){
    return c->front == -1;
}

void add_rear(Deque *d, int *value){
    if(is_full(d)){
        printf("Queue is full\n");
        return;
    }
    d->rear = (d->rear + 1) % MAX;
    d->queue[d->rear] = value;   
    if(d->front == -1){
        d->front = 0; 
    }
}

void add_front(Deque *d, int *value){
    if(is_full(d)){
        printf("Queue is full \n");
        return;
    }
    if(d->front == -1){ 
        d->front = 0; 
        d->rear = 0;
        d->queue[d->front] = value;  
    } else {
        d->front = (d->front - 1 + MAX) % MAX;
        d->queue[d->front] = value;
    }    
}

void remove_front(Deque *d){
    if(is_empty(d)){
        printf("Queue is empty \n");
        return;
    }
    if(d->front == d->rear){
        d->front = -1;
        d->rear = -1;
    } else {
        d->front = (d->front + 1) % MAX;
    }
}

void remove_rear(Deque *d){
    if(is_empty(d)){
        printf("Queue is empty");
        return;
    }
    if(d->front == d->rear){  
        d->front = -1;
        d->rear = -1;
    } else {
        d->rear = (d->rear - 1 + MAX) % MAX;
    }
}

void display_deque(Deque *d){
    if(is_empty(d)){
        printf("The deque is currently empty.\n\n");
        return;
    }
    int count = (d->rear + MAX - d->front) % MAX + 1; 
    int current_index = d->front;
    printf("[");
    for (int i = 0; i < count; i++){
        printf("%d,", *(d->queue[current_index]));
        current_index = (current_index + 1) % MAX;
    }
    printf("]");
}