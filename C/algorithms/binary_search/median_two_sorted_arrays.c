// Algorithm: Median of Two Sorted Arrays 
// Pattern: Binary searches the smaller array to find the perfect partition line where 
// all elements on the left of both arrays are smaller than all elements on the right.
// (LeetCode 4)

#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int a[], int n1, int b[], int n2) {
    if (n1 > n2) return findMedianSortedArrays(b, n2, a, n1);

    int n = n1 + n2;
    int t = (n + 1) / 2;
    int low = 0, high = n1;

    while (low <= high) {
        int x = (low + high) / 2;
        int y = t - x;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (x < n1) r1 = a[x];
        if (y < n2) r2 = b[y];
        if (x - 1 >= 0) l1 = a[x - 1];
        if (y - 1 >= 0) l2 = b[y - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1)
                return (double)(l1 > l2 ? l1 : l2);
            else {
                int left_max = (l1 > l2 ? l1 : l2);
                int right_min = (r1 < r2 ? r1 : r2);
                return (left_max + right_min) / 2.0;
            }
        } else if (l1 > r2)
            high = x - 1;
        else
            low = x + 1;
    }
    return -1; // Should never reach here if inputs are valid
}

int main() {
    int a[] = {1, 3, 4, 7, 10, 12};
    int b[] = {2, 3, 6, 15};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    printf("Median = %.2f\n", findMedianSortedArrays(a, n1, b, n2));
    return 0;
}