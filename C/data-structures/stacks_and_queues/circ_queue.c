// Data Structure: Circular Queue
// Mechanics: FIFO. Uses modulo arithmetic to wrap the rear pointer back to the 
// beginning of the array, preventing "false overflow".

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5
#define TEST_ARRAY {1,2,3,4,5}

typedef struct {
    int size;
    char* queue[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// --- Prototypes ---
void init(CircularQueue *c);
bool isFull(CircularQueue *c);
bool is_empty(CircularQueue *c);
void enqueue(CircularQueue *c, char* value);
void dequeue(CircularQueue *c);
void display_line(CircularQueue *c);

// --- Test Execution ---
int main(){
    CircularQueue queue;
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
    enqueue(&queue, e);
    
    // Will reject because Queue is full
    enqueue(&queue, f); 

    display_line(&queue);

    dequeue(&queue);
    display_line(&queue);

    dequeue(&queue);
    dequeue(&queue);

    char *g = "Homer";
    enqueue(&queue, g);

    display_line(&queue);

    return 0;
}

// --- Utility Implementations ---
void init(CircularQueue *c){
    c->size = MAX_SIZE;
    c->front = -1;
    c->rear = -1;
}

bool isFull(CircularQueue *c){
    return (c->rear + 1) % c->size == c->front;
}

bool is_empty(CircularQueue *c){
    return c->front == -1;
}

void enqueue(CircularQueue *c, char* value){
    if(isFull(c)){
        printf("Queue is full\n");
        return;
    }
    c->rear = (c->rear + 1) % c->size;
    c->queue[c->rear] = value;
    
    if(c->front == -1){
        c->front = 0;
    }
}

void dequeue(CircularQueue *c){
    if(is_empty(c)){
        printf("Queue is empty \n");
        return;
    }
    if(c->front == c->rear){
        c->front = -1;
        c->rear = -1;
    } else {
        c->front = (c->front + 1) % c->size;
    }   
}

void display_line(CircularQueue *c){
    if(is_empty(c)){
        printf("Line is empty \n");
        return;
    }
    
    // Safe circular count formula
    int count = (c->rear + c->size - c->front) % c->size + 1;
    
    printf("Currently there are %d persons in line \n", count);
    printf("The first person in line is %s \n", c->queue[c->front]);
    printf("The last person to get in line is %s \n\n", c->queue[c->rear]);
}