// Algorithm: Rotate Array (With Auxiliary Space)
// Time: O(n) | Space: O(n)
// Pattern: Uses modulo arithmetic ( (i + k) % n ) to perfectly map shifted indices into a new array.

#include <stdlib.h>
#include <stdio.h>

#define K -2

//algorithm
void rotate_array(int n, int old_arr[], int new_arr[], int k){
    k = ((k % n) + n) % n; // normalizer for negative rotations

    for(int i = 0; i < n; i++){
        new_arr[(i + k) % n] = old_arr[i];
    }
}
//
void display_arr(int n, int arr[]);

int main(){
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    int new_arr[n];

    rotate_array(n, array, new_arr, K);
    
    printf("Array after rotation: \n");
    display_arr(n, new_arr);

    return 0;
}

void display_arr(int n, int arr[]){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}