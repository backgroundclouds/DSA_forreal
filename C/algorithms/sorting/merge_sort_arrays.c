//merge sort for arrays

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int *left_arr = malloc(n1 * sizeof(int));
    int *right_arr = malloc(n2 * sizeof(int));

    if(left_arr == NULL || right_arr == NULL){
        printf("Memory issue \n");
        free(left_arr);
        free(right_arr);
        return;
    }

    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = start;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    free(left_arr);
    free(right_arr);
}


///Update this

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
	
  	// Sorting arr using mergesort
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}