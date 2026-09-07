// Specialized hash table with separate chaining. 
// Maps a sorted string key to an expanding array of anagrams. 
// Saved specifically as a clean reference for handling collisions and dynamic memory in C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT {"listen", "silent", "enlist", "google", "gooegl", "elbow", "below", "bored", "robed"}

#define HASH_SIZE 50000

typedef struct Entry {
    char *key;
    char **wordList; 
    int wordCount;
    struct Entry *next;
} Entry;

Entry* createEntry(char *key){
    Entry *entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->wordList = malloc(10000 * sizeof(char *));
    entry->wordCount = 0;
    entry->next = NULL;

    return entry;
}

int hash(char *string){
    int hashVal = 0;
    while(*string){
    hashVal = (hashVal * 31 + *(string++)) % HASH_SIZE;
    }
    return hashVal;
}
int comp(const void *a, const void *b){
   return *(char *)a - *( char *)b ;
};

bool keysDifferent(char *existing_key, char *target_key){ //renamed
    return strcmp(existing_key, target_key) != 0;
}

char *getKey(char *string){
    char *key = malloc(101 * sizeof(char)); /// maybe?
    strcpy(key, string);
    int length = strlen(key);
    qsort(key, length, sizeof(key[0]), comp);
    return key;
}

Entry **hashAnagrams(char **strings, int stringCount){
    //create hashtable  
    Entry **hashTable = malloc(HASH_SIZE * sizeof(Entry *));
    memset(hashTable, 0, HASH_SIZE * sizeof(Entry *));

    for(int i =0; i < stringCount; i++){
         //create key and entry for each string, 
        char *string = strings[i];
        char *key = getKey(string); // reduce it to numerical ascii value
        int index = hash(key);
        //create entry pointer, point it at would be-index
        Entry *entry = hashTable[index]; 
        Entry *prev = NULL; //create prev pointer for traversing (if needed)

        //Search
        //Traverse until entry is null, and the keys are different
        while(entry != NULL && keysDifferent(entry->key, key)){ 
            prev = entry;
            entry = entry->next;
        }
         //CASE 1: If prev is NULL. No traversal happened, and entry is first available.
        if (entry == NULL && prev == NULL ){
            Entry *newEntry = createEntry(key); 
            newEntry->wordList[newEntry->wordCount++] = string;
            hashTable[index] = newEntry; // assign entry to hashtable
        }
        //CASE 2: Collision occured. Entry found, but keys don't match. 
        else if ( entry == NULL && prev != NULL ){
            Entry *newEntry = createEntry(key); 
            newEntry->wordList[newEntry->wordCount++] = string;
            prev->next = newEntry; //Link 1st entry to 2nd.
        } else { 
        //CASE 3: Entry is not null. And keys match.
            free(key);
            entry->wordList[entry->wordCount++] = string;
        }
    }
    return hashTable;
}


void displayAnagrams(Entry **hashTable) {
    printf("[\n");
    bool isFirstGroup = true;

    // Scan the hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        Entry *entry = hashTable[i];
        // Traverse any collisions
        while (entry != NULL) {
            // PREFIX formatting trick for clean trailing commas
            if (!isFirstGroup) {
                printf(",\n");
            }
            isFirstGroup = false;
            // Print the individual group
            printf("  [");
            for (int j = 0; j < entry->wordCount; j++) {
                printf("\"%s\"", entry->wordList[j]);
                // Add comma between words, but not after the last word
                if (j < entry->wordCount - 1) {
                    printf(", ");
                }
            }
            printf("]");
            
            entry = entry->next;
        }
    }
    
    printf("\n]\n");
}

void freeHashTable(Entry **hashTable) {
    // 1. Loop through every bucket in the hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        Entry *current = hashTable[i];
        
        // 2. Traverse the linked list (if there is one)
        while (current != NULL) {
            // Save the next pointer before we destroy the current node
            Entry *nextEntry = current->next;
            
            // 3. Free the inner dynamically allocated parts first
            free(current->key);
            free(current->wordList);
            
            // 4. Free the struct node itself
            free(current);
            
            // Move to the next node in the chain
            current = nextEntry;
        }
    }    
    // 5. Finally, free the master array of buckets
    free(hashTable);
}
int main(){
    char* strings[] = INPUT;
    int n = sizeof(strings)/sizeof(strings[0]);

    Entry **hashTable = hashAnagrams(strings, n);
    displayAnagrams(hashTable);

    freeHashTable(hashTable);
    return 0;
}



