// Algorithm: Binary Search on Sorted Rotated Array
// 1. Determines which half is the sorted half.
// 2. Determines IF the target value is within that sorted half.
//    - If it is, narrows search to that space.
//    - If not, eliminates the sorted space entirely.
// Always assumes target will be within the sorted space somewhere.
// Note: Does not include duplicate logic.
//LeetCode (33)

#include <stdio.h>
int search(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        // Check which half is sorted
        if (arr[left] <= arr[mid]) {
            // Left half is sorted
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            // Right half is sorted
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;  // Not found
}