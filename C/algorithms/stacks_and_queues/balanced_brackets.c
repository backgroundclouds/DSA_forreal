// Algorithm: Balanced Brackets
//Return True or False if sequence has balanced brackets
// Time: O(n) | Space: O(n)
// Pattern: Uses a stack to track open brackets and validates them against incoming closed brackets.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define STACK_MAX 25
#define TEST_STRING "[{()}]"

typedef struct {
    int top;
    char arr[STACK_MAX];
} Stack;

// --- Prototypes ---
void init(Stack *stack);
char pop(Stack *stack);
void push(Stack *stack, char value);
char peek(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);

// --- Core Algorithm ---
bool is_open_bracket(char i){
    if (i == '{' || i == '[' || i == '(') return true;
    return false;
}

bool is_closed_bracket(char i){
    if (i == '}' || i == ']' || i == ')') return true;
    return false;
}

bool bracket_matches(char popped, char i){
    if(popped == '{' && i == '}') return true;
    if(popped == '[' && i == ']') return true;
    if(popped == '(' && i == ')') return true;
    return false;
}

int main(){
    Stack stack;
    init(&stack);
    char *string = TEST_STRING;
    int n = strlen(string);

    for(int i = 0; i < n; i++){
        if(is_open_bracket(string[i])){
            push(&stack, string[i]);
        }
        else if(is_closed_bracket(string[i])){
            if (stack.top < 0){ //stack is empty therefore no match
                return 1;
            }
            char peeked = peek(&stack);
            if(bracket_matches(peeked, string[i])){
                pop(&stack);
                continue; 
            }
            else{ //if false no match
                return 1;
            }
        }
    }
    //if loop complete succesfully
    if(isEmpty(&stack)){
        return 0;
    }
    else{
        return 1;
    }
}

// --- Stack Utilities ---
void init(Stack *stack){
    stack->top =-1;
    return;
}
char pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty \n");
        exit(EXIT_FAILURE);
    }
    char popped = stack->arr[stack->top];
    stack->top = stack->top-1;
    return popped;
}
void push(Stack *stack, char value){
    if(isFull(stack)){
        printf("Stack is full \n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}
char peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty \n");
        return '\0';
    }
    return stack->arr[stack->top];
}
bool isFull(Stack *stack){
    return stack->top == STACK_MAX;
}
bool isEmpty(Stack *stack){
    return stack->top == -1;
}