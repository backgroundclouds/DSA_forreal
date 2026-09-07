// Algorithm: Subarrays with Given Sum and Bounded Maximum
// Time: O(n^2) worst-case | Space: O(1)
// Pattern: Nested loops to evaluate contiguous subarrays, using an early exit if an element exceeds the bound M.
//HackerRank problem 'Subarrays with Given Sum and Bounded Maximum'

#include <stdio.h>
#include <stdlib.h>

// --- Prototypes ---
long countSubarraysWithSumAndMaxAtMost(int nums_count, int* nums, long k, long M);

// --- Core Algorithm ---
long countSubarraysWithSumAndMaxAtMost(int nums_count, int* nums, long k, long M) {
    long commits = 0;
    
    for(int i = 0; i < nums_count; i++){
        long currentValue = 0; 
        
        for(int j = i; j < nums_count; j++){
            if(nums[j] > M){
                break; 
            }
            
            currentValue = currentValue + nums[j];
            
            if(currentValue == k){
                commits++;
            }
        }
    }

    return commits;
}

// --- Test Execution ---
int main() {
    int nums[] = {2, -1, 2, 1, -2, 3};
    int nums_count = sizeof(nums) / sizeof(nums[0]);
    long k = 3;
    long M = 2;

    long result = countSubarraysWithSumAndMaxAtMost(nums_count, nums, k, M);
    printf("Valid subarrays count: %ld\n", result); 

    return 0;
}