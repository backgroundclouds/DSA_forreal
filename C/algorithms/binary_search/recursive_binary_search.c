// Algorithm: Recursive Binary Search
// Time: O(log n) | Space: O(log n) (due to recursion stack)
// Pattern: Divide and conquer. Halves the search space at each step by comparing the target to the midpoint.

#include <stdio.h>
#include <stdbool.h>

#define TEST_ARRAY {3, 6, 17, 19, 23, 30, 50}
#define TEST_TARGET 40

int binary_search(int *arr, int low, int high, int target) {
    if(low > high){
        return -1;
    }
    
    int mid = low + (high - low) / 2;

    if(arr[mid] == target){
        return mid;
    }
    
    if (arr[mid] < target){
        return binary_search(arr, mid + 1, high, target);
    } else {
        return binary_search(arr, low, mid - 1, target);
    }
}

int main() {
    int arr[] = TEST_ARRAY;
    int x = TEST_TARGET;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = binary_search(arr, 0, n - 1, x);
    printf("%d \n", result);
    
    return 0;
}