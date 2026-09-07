// Longest Subarray with Sum Equal to Target (Prefix Sum + Hash Map)
// Time: O(n) | Auxiliary Space: O(n)
// Pattern: Uses cumulative prefix sums and a hash map to track the earliest 
// index of each sum, allowing instantaneous complement lookup (current_sum - k).
// LeetCode 325 


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INPUT {3, 1, -1, 2, -1, 5, -2, 3}
#define TARGET 3

#define HASH_SIZE 11111

typedef struct Entry {
    int key;          
    int value;          
    struct Entry* next;
} Entry;

typedef struct {
    Entry* buckets[HASH_SIZE];
} HashMap;
// --- Datastructure Prototypes ---
Entry* create_entry(int key, int value );
int get_hash(int key);
void put(HashMap* map, int key, int val_to_add);
int get(HashMap* map, int key);
void free_map(HashMap* map);
// --- Algo Helpers ---
bool check(HashMap* map, int key){
    int index = get_hash(key);
    Entry *current = map->buckets[index];

    while( current != NULL){
        if(current->key == key){
            return true;
        }
        current = current->next;
    }
    return false;

}

int max(int a, int b){
    return (a > b) ? a : b; 
}
// --- Core Algorithm ---
int longest_arr_ksum(int arr[], int n, int k){
    HashMap hashmap = {0};
    int current_sum = 0;
    int max_length = 0;

    for (int i =0; i<n; i++){
        current_sum += arr[i];

        if(current_sum == k){
            max_length = i + 1 ;
        }
        int complement = current_sum - k;
        if((check(&hashmap, complement))){
            int old_index = get(&hashmap, complement);
            int current_length = i - old_index;
            max_length = max(max_length, current_length);
        }

        if((!check(&hashmap, current_sum))){
            put(&hashmap, current_sum, i);
        }
    }
    free_map(&hashmap);
    return max_length;
};

int main() {
    int arr[] = INPUT;
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = TARGET;
    printf("Result : %d\n", longest_arr_ksum(arr, n, target));

    return 0;
}


Entry* create_entry(int key, int value ) {
    Entry* entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

int get_hash(int key) {

    int hash_val = key % HASH_SIZE;
    return hash_val < 0 ? hash_val + HASH_SIZE : hash_val;
    }
int get(HashMap* map, int key) {
    int index = get_hash(key);
    Entry* current = map->buckets[index];
    
    while (current != NULL) { //traverse until we hit the right key
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return INT_MIN; 
}
void free_map(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; ++i) {
        Entry* current = map->buckets[i];
        while (current != NULL) {
            Entry* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
void put(HashMap* map, int key, int val_to_add) {
    int index = get_hash(key);
    Entry* current = map->buckets[index];

    //traverse if needed
    while (current != NULL) {
        if (current->key == key) {

            return;
        }
        current = current->next; //traverse until NULL, unless key match occurs
    }
    
    Entry* new_entry = create_entry(key, val_to_add);

    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
}
