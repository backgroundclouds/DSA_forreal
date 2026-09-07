//// Find missing numbers in range [0, n-1] using an O(n) boolean lookup table.
//Allocates extra space/memory, unlike the array in place algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TEST_ARRAY {4,5,2,7,1,2,7,1} 

void display(int arr[], int n);

void finddisappeared_index(int arr[ ], int n){

    bool* set = calloc(n, sizeof(bool));

    for(int i = 0; i< n; i++){ //index truthy values into set
        set[arr[i]] = true;
    }

    int *missing = malloc(n * sizeof(int));
    int append =0; //note which are missing
    for(int i =0; i<n; i++){
        if(!set[i]){
            missing[append] = i;
            append++;
        }
    }
    missing = realloc(missing, append * sizeof(int));
    display(missing, append);
    free(missing);

    return;
};
int main(){
    int arr[] = TEST_ARRAY;
    int n = sizeof(arr)/sizeof(arr[0]);

    finddisappeared_index(arr, n);
    
    return 0;
}
void display(int arr[], int n){
    printf("\n");
    for(int i =0; i< n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}