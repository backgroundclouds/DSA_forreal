// Data Structure: Array-based Stack
// Mechanics: LIFO (Last In, First Out).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    char *clothes[MAX_SIZE]; //
    int top;

}Stack;

void initialize_stack(Stack *stack){
    stack->top = -1;
}

bool isEmpty(Stack *stack){
    if(stack->top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Stack *stack){
    if(stack->top == MAX_SIZE){
        return true;
    }
    return false;
}

void peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty \n");
    }
    else{
        int i = stack->top;
        char *value = stack->clothes[i];
        printf("Stack is at [%d] : %s", i, value);
    }
}

void push(Stack *stack, char *value){
    if(isFull(stack)){
        printf("Stack is full \n");
        return;
    }
    int i = ++stack->top;
    stack->clothes[i] = value;    
    printf("%s added to top of stack \n", value);

}

void pop(Stack *stack){
    //if empty
    if(isEmpty(stack)){
        printf("Stack is empty \n");
        return;
    }
    char *popped = stack->clothes[stack->top];
    stack->top--;
    printf("%s popped from stack \n", popped);
}


int main(){
    char* a = "red shirt";
    char* b = "stripped shirt";
    char* c = "black shirt";
    char* d = "polka dot shirt";

    Stack stack;
    initialize_stack(&stack);
    push(&stack, a);
    push(&stack, b);
    push(&stack, c);
    push(&stack, d);

    peek(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    peek(&stack);

    return 0;
}