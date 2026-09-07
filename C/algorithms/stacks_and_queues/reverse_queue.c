// Algorithm: Reverse a Queue (Recursively)
// Time: O(n) | Space: O(n) (Implicitly uses the call stack)
// Pattern: Pops an item, pauses execution to recursively call itself until empty, 
// then pushes items back on as the call stack unwinds (reversing the order).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Q_MAX 25
#define TEST_DATA {1, 2, 3, 4, 5, 6, 7, 8, 9}

typedef struct {
    int line[Q_MAX];
    int front;
    int rear;
} Queue;

// --- Prototypes ---
void init_q(Queue *q);
bool is_full(Queue *q);
bool is_empty(Queue *q);
void add_rear(Queue *q, int value);
int remove_front(Queue *q);
void display(Queue *q);

// ---  Algorithm ---
void reverse_queue(Queue *q){
    //base case
    if(is_empty(q)){
        return;
    }
    //each pop
    int value = remove_front(q);

    //recursion
    reverse_queue(q);

    //runs after base case conditional met
    add_rear(q, value);
}


int main(){
    Queue q;
    init_q(&q);
    
    int array[] = TEST_DATA;
    int n = sizeof(array)/sizeof(array[0]);
    
    for(int i = 0; i < n; i++){
        if(n > Q_MAX){
            printf("Test Array exceeds Queue capacity \n");
            return 1;
        }
        add_rear(&q, array[i]);
    }
 
    display(&q);
    printf(" reversed -> ");
    
    reverse_queue(&q);
    
    display(&q);
    printf("\n");

    return 0;
}


void init_q(Queue *q){
    q->front = -1;
    q->rear = -1;
}

bool is_full(Queue *q){
    if(q->front == (q->rear + 1) % Q_MAX) //if next step for rear overlaps w/ front, then full
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_empty(Queue *q){
    if(q->front == -1){
        return true;
    }
    else{
        return false;
    }
}

void add_rear(Queue *q, int value){
    if(is_full(q)){
        printf("is full \n");
        return;
    }
    if(is_empty(q)){
        q->rear = 0;
        q->front = 0;
        q->line[q->rear] = value;
        return;
    }
    q->rear = (q->rear + 1) % Q_MAX;
    q->line[q->rear] = value;
}

int remove_front(Queue *q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return -1;
    }
    int dequeued = q->line[q->front];
    if(q->front == q->rear){ //adjust for empty
        q->front = -1;
        q->rear = -1;
        return dequeued;
    }
    else{
        q->front = (q->front + 1) % Q_MAX;
        return dequeued;
    }
}

void display(Queue *q){
    if(is_empty(q)){
        printf("queue is empty \n");
        return;
    }
    //get count //circular distance formula 
    int count = (q->rear + Q_MAX - q->front) % Q_MAX + 1;
    int true_index = q->front;
    
    printf("[ ");
    for(int i = 0; i < count; i++){
        printf(" %d ", q->line[true_index]);
        true_index = (true_index + 1) % Q_MAX;
    }
    printf(" ]");
}