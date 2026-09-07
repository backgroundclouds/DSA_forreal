//// Find missing numbers in range [1, n] using in place array-marking (negation)
//for found values, take found value, go to the zero based index that matches value. -> Mark value at said index as negative
//Can handle n. //Cannot handle 0's.
// LeetCode 448: Find All Numbers Disappeared in an Array.

#include <stdio.h>
#include <stdlib.h>

#define TEST_ARRAY {4, 3, 2, 7, 1, 2, 3, 1}

void display(int arr[], int n);
void find_dissapeared_inplace(int arr[], int n ){
    for(int i = 0; i < n; i++){
        int index = abs(arr[i]) - 1;
        if (index < n){
            arr[index] = -abs(arr[index]);
        }
    }
    int append = 0;
    int *results = malloc(n * sizeof(int));
    for (int i =0; i < n; i++){
        if(arr[i] > 0){ 
            results[append] = i+1;
            append++;
        };
    }
    results = realloc(results, append * sizeof(int));
    display(results, append);
    free(results);
    return;
};

int main(){
    int arr[] = TEST_ARRAY;
    int n = sizeof(arr)/sizeof(arr[0]);


    find_dissapeared_inplace(arr, n);
    
    return 0;
}
void display(int arr[], int n){
    printf("\n");
    for(int i =0; i< n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}