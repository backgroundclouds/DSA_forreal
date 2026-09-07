// Algorithm: Median of Two Rotated Sorted Arrays (Unique Elements)
// Time: O(log n) | Space: O(1)
// Pattern: Advanced variant. Uses binary search to find the pivot of both arrays first, then normalizes indices using modulo arithmetic during the standard median partition search.
// Solves HackerRank (Median of Two Circularly Sorted Logs)


#include <stdio.h>
#include <limits.h>

// --- Prototypes ---
int getPivot(long* arr, int n);
long findMedianInRotatedSortedArrays(int A_count, long* A, int B_count, long* B);

// --- Core Algorithm ---
int getPivot(long* arr, int n){
    int high = n - 1;
    int low = 0;
    
    while(low < high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[high]){
            low = mid + 1;
        } else {
            high = mid;
        }    
    }
    return low;
}

long findMedianInRotatedSortedArrays(int A_count, long* A, int B_count, long* B) {
    int n1 = A_count;
    int n2 = B_count;
    if (n1 > n2) return findMedianInRotatedSortedArrays(B_count, B, A_count, A);
    
    int pivotA = getPivot(A, n1);
    int pivotB = getPivot(B, n2);
    
    int n = n1 + n2;
    int high = n1;
    int low = 0;
    int t = (n + 1) / 2;
    
    while (low <= high){
        int x = (low + high) / 2;
        int y = t - x;
        
        long l1 = LONG_MIN, l2 = LONG_MIN;
        long r1 = LONG_MAX, r2 = LONG_MAX;
        
        if (x < n1) r1 = A[(x + pivotA) % n1]; 
        if (y < n2) r2 = B[(y + pivotB) % n2];
        if (x - 1 >= 0) l1 = A[(pivotA + x - 1 + n1) % n1];
        if (y - 1 >= 0) l2 = B[(pivotB + y - 1 + n2) % n2]; 
        
        if (l1 <= r2 && l2 <= r1) {
            return (l1 > l2 ? l1 : l2);   
        }
        else if (l1 > r2) {
            high = x - 1; 
        }
        else {
            low = x + 1;
        }    
    }
    return -1;
}

// --- Test Execution ---
int main() {
    long A_test1[] = {4, 5, 1, 2, 3};
    long B_test1[] = {8, 9, 6, 7};
    long median1 = findMedianInRotatedSortedArrays(5, A_test1, 4, B_test1);
    printf("Test 1 Median = %ld\n", median1); // Expected: 5

    long A_test2[] = {10, 11, 12, 1, 2, 3};
    long B_test2[] = {7, 8, 9, 4, 5, 6};
    long median2 = findMedianInRotatedSortedArrays(6, A_test2, 6, B_test2);
    printf("Test 2 Median = %ld\n", median2); // Expected: 6

    return 0;
}