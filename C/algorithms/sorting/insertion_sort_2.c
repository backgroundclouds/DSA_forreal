//My preferred version of Insertion Sort Best: O(n), Worst: O(n^2).
//Compare each index to the preceeding block of array prior to it
//INSERTING the comparison index btwn the values its greater than and lesser to

#include <stdio.h>
#include <stdlib.h>

#define TEST_ARRAY { 99, 4, 7, 5, 13, 12, 44, 42, 0 , 44}

void display(int arr[], int n);
void swap(int *i, int *j);
void insertion_sort(int arr[], int n){
   
    for(int i = 1; i< n; i++){
        int j = i;
        while(j > 0){
            if(arr[j-1] > arr[j] ){
                swap(&arr[j-1], &arr[j]);
                j--;
            }
            else{
                break; 
            }
        }
}


}
int main(){
    int arr[] = TEST_ARRAY;
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr, n);

    insertion_sort(arr, n);
    display(arr, n);

    return 0;
}
void display(int arr[], int n){
    printf("\n");
    for(int i =0; i< n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *i, int *j){
    int temp = *i;

    *i = *j;
    *j = temp;
    return;
}