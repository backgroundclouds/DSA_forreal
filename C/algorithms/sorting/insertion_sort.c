// Standard insertion sort implementation. Best: O(n), Worst: O(n^2).

#include <stdio.h>
#include <stdlib.h>

#define TEST_ARRAY { 99, 4, 7, 5, 13, 12, 44, 42, 0 , 44}

void display(int arr[], int n);
void insertion_sort(int arr[], int n){
    for (int i =1; i< n; i++){
        int temp = arr[i];
        int position = i-1;
        while(position>=0){
            if(arr[position] > temp){
                arr[position+1] = arr[position];
                position = position -1 ; //decremement, check next left
            }
            else{
                break;
            }
        }
        arr[position+1] = temp;
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