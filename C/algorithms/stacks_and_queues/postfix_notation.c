// Algorithm: Evaluate Postfix Notation (RPN)
//Return the arithmetic of the express as it would be performed in Reverse Polish Notation
//IE Input: "3 4 +" Output: 7.0
// Input: "10 2 /" Output: 5.0
// Input: "3 2 + 2 /" Output: 2.5
// Input: "5 1 2 + 4 * + 3 -" Output: 14.0
// Time: O(n) | Space: O(n)
// Pattern: Pushes numbers to a stack. When an operator is found, pops two numbers, evaluates, and pushes the result back.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 25
#define TEST_STRING "3 2 + 2 /"

typedef struct {
    int top;
    double arr[MAX_STACK];
} Stack;

// --- Prototypes ---
void init_stack(Stack *stack);
double pop(Stack *stack);
void push(Stack *stack, double value);
void peek(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);

// --- Core Algorithm ---
int char_check(char i){
    if(isdigit(i)){
        return 1;
    }
    if((isalpha(i)) || (isspace(i))){
        return 2;
    }
    if(strchr("+-*/", i)){
        return 3;
    }
    else{
        return 4; // edge case idk
    }
}

void answer (Stack *stack, char *string){
    if(isEmpty(stack)){
        printf("Stack is empty \n");
        return;
    }
    double output = stack->arr[stack->top];
    printf("Input: \"%s\" Output: %.1f \n", string, output);
    return;
}

int main(){
    Stack num_stack;
    init_stack(&num_stack);
    char *string = TEST_STRING;
    int n = strlen(string);

    for (int i = 0; i < n; i++){
        int chk = char_check(string[i]);
        
        switch (chk){
            case 1: ; //compiler
                int j = 0;
                char string_num[10] = "";
                while (!isspace(string[i + j]) && string[i + j] != '\0'){
                    string_num[j] = string[i+j];
                    j++;
                };
                double num = strtol(string_num, NULL, 10);
                push(&num_stack, num);
                i = i+j;
                break;
            case 2: 
                //do nothing
                break; 
            case 3: //operators
                if(string[i]== '+'){
                    double first = pop(&num_stack);
                    double second = pop(&num_stack);
                    push(&num_stack, second + first);
                    break;
                }
                if(string[i]== '*'){
                    double first = pop(&num_stack);
                    double second = pop(&num_stack);
                    push(&num_stack, second * first);
                    break;
                }
                if(string[i]== '/'){
                    double first = pop(&num_stack);
                    double second = pop(&num_stack);
                    push(&num_stack, second / first);
                    break;
                }
                if(string[i]== '-'){
                    double first = pop(&num_stack);
                    double second = pop(&num_stack);
                    push(&num_stack, second - first);
                    break;
                }                
        }
    }
    answer(&num_stack, string);
    return 0;
}

// --- Stack Utilities ---
void init_stack(Stack *stack){
    stack->top = -1;
}
double pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty \n");
        exit(EXIT_FAILURE);
    }
    double popped = stack->arr[stack->top];
    stack->top = stack->top-1;
    return popped;
}
void push(Stack *stack, double value){
    if(isFull(stack)){
        printf("Stack is full \n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}
void peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty \n");
        return;
    }
    double peek = stack->arr[stack->top];
    printf("Stack is at [%d] : [%.1f] \n", stack->top, peek);
    return;
}
bool isFull(Stack *stack){
    return stack->top == MAX_STACK;
}
bool isEmpty(Stack *stack){
    return stack->top == -1;
}