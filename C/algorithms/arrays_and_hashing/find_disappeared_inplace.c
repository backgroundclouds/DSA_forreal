// Missing Number Tracker
// Algorithmn to find missing values with an integer
// Assumes values are within [0, n-1] range range
// Is able to find values in-place, w/o using an addtl. datastructure.
// Footprints indices by adding n to the value at index
// Retrieves original value through normalization 'value % n'

#include <stdio.h>
#include <stdlib.h>

#define TEST_ARRAY {3, 0, 6, 7, 3, 3, 3, 4, 7} 

void display(int arr[], int n);
void find_dissapeared_inplace(int arr[], int n ){
    for(int i = 0; i < n; i++){
        int index = arr[i] % n; 
        if (arr[index]  < n){ //screens duplicates
            arr[index] += n;
        }
    }

    int append = 0;
    int *missing = malloc(n * sizeof(int));
    for (int i =0; i < n; i++){
        if(arr[i] < n){ //if value at i is not greater than n, than i itself was never used 
            missing[append] = i;
            append++;
        };
    }
    missing = realloc(missing, append * sizeof(int));
    display(missing, append);
    free(missing);
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