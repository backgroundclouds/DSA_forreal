// Algorithm: Fisher-Yates Shuffle
// Time: O(n) | Space: O(1)
// Pattern: Iterates backward, swapping the current element with a randomly chosen element from the remaining unshuffled portion.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

// --- Prototypes ---
void fill_array(int n, int array[]);
void swap_values(int *a, int *b);
void print_array(int n, int array[]);

// --- Algorithm ---
void shuffle_array(int n, int array[]){
    srand(time(NULL));
    
    for(int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap_values(&array[i], &array[j]);
    }
}


int main(){
    int array[N] = {0};
    
    fill_array(N, array);
    printf("Initial array: \n");
    print_array(N, array);
    
    shuffle_array(N, array);
    printf("\nShuffled array: \n");
    print_array(N, array);

    return 0;
}

void fill_array(int n, int array[]){
    for(int i = 0; i < n ; i++){
        array[i] = i; 
    }
}

void swap_values(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print_array(int n, int array[]){
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}