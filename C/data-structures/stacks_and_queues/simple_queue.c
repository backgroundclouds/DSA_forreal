// Data Structure: Simple Linear Queue
// Mechanics: FIFO (First In, First Out). 
// Warning: Suffers from "false overflow". Once rear reaches MAX_SIZE, it cannot add more 
// items even if dequeueing has freed up space at the front.
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20

typedef struct {
    char* queue[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q){
    q->front=0;
    q->rear=-1;
};

bool isFull(Queue *q){
    if(q->rear+1 == MAX_SIZE){
        return true;
    }
    return false;
}
bool is_empty(Queue *q){
    if(q->front > q->rear){
        return true;
    }
    return false;
}
void enqueue(Queue *q, char* value){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    //iterate value
    ++q->rear;
    q->queue[q->rear] = value;
    // printf("DEBUG rear: %d \n", q->rear);
    // printf("DEBUG value: %s \n", q->queue[q->rear]);
    //assign to array
}
void dequeue(Queue *q){
    if(is_empty(q)){
        printf("Queue is empty \n");
        return;
    }
    q->front++;
}
void display_line(Queue *q){
    int count = (q->rear+1) - q->front;
    printf("Currently there are %d persons in line \n", count);
    printf("The first person in line is %s \n", q->queue[q->front]);
    printf("The last person to get in line is %s \n \n", q->queue[q->rear]);
    
}



int main(){
    Queue queue;
    init(&queue);

    char *a = "Larry";
    char *b = "Frank";
    char *c = "Steve";
    char *d = "Georgie";

    char *e = "Fuck Face";
    char *f = "Fuck Face the III";

    enqueue(&queue, a);
    enqueue(&queue, b);
    enqueue(&queue, c);
    enqueue(&queue, d);

    display_line(&queue);

    dequeue(&queue);

    enqueue(&queue, e);
    enqueue(&queue, f);

    display_line(&queue);

    dequeue(&queue);
    dequeue(&queue);

    // display_line(&queue);

    char *g = "Homer";

    enqueue(&queue, g);

    display_line(&queue);

    return 0;
}