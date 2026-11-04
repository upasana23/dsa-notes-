#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 1009 // A prime number for better hash distribution

// Node structure for Hash Table chaining
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hash function mapping a value to a table index
int hash_function(int value) {
    int hash = value % HASH_SIZE;
    if (hash < 0) hash += HASH_SIZE; // Handle negative integers
    return hash;
}

// Comparison function needed for qsort
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * 1. SORTING-BASED DETECTION
 * Modifies the array in-place to group duplicates together.
 * Time: O(N log N) | Auxiliary Space: O(1)
 */
void find_duplicates_sort(int arr[], int size) {
    if (size <= 1) return;

    // Sort the array in ascending order
    qsort(arr, size, sizeof(int), compare_ints);

    printf("Duplicates found (Sorting Method): ");
    bool found = false;
    
    // Check adjacent elements
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            // Print the duplicate only once even if it appears multiple times
            if (i == 1 || arr[i] != arr[i - 2]) {
                printf("%d ", arr[i]);
                found = true;
            }
        }
    }
    if (!found) printf("None");
    printf("\n");
}

/**
 * 2. HASH-BASED DETECTION (Comparison)
 * Tracks visited elements using a hash table.
 * Time: O(N) average | Auxiliary Space: O(N)
 */
void find_duplicates_hash(int arr[], int size) {
    // Initialize Hash Table buckets to NULL
    Node* hash_table[HASH_SIZE] = { NULL };
    // Track printed duplicates to avoid multi-printing the same value
    Node* printed_table[HASH_SIZE] = { NULL }; 

    printf("Duplicates found (Hash Method): ");
    bool found = false;

    for (int i = 0; i < size; i++) {
        int val = arr[i];
        int index = hash_function(val);

        // Look up if we have seen this value before
        Node* curr = hash_table[index];
        bool already_seen = false;
        
        while (curr != NULL) {
            if (curr->data == val) {
                already_seen = true;
                break;
            }
            curr = curr->next;
        }

        if (already_seen) {
            // Check if we already flagged/printed this duplicate
            int p_index = hash_function(val);
            Node* p_curr = printed_table[p_index];
            bool already_printed = false;
            
            while (p_curr != NULL) {
                if (p_curr->data == val) {
                    already_printed = true;
                    break;
                }
                p_curr = p_curr->next;
            }

            if (!already_printed) {
                printf("%d ", val);
                found = true;
                
                // Add to printed table
                Node* new_p_node = (Node*)malloc(sizeof(Node));
                new_p_node->data = val;
                new_p_node->next = printed_table[p_index];
                printed_table[p_index] = new_p_node;
            }
        } else {
            // First time seeing it: Add it to the seen hash table
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->data = val;
            new_node->next = hash_table[index];
            hash_table[index] = new_node;
        }
    }
    if (!found) printf("None");
    printf("\n");

    // Memory Cleanup
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hash_table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        curr = printed_table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// --- Demonstration ---
int main() {
    // Sample datasets
    int data1[] = {45, 12, 89, 12, 34, 45, 78, 45};
    int data2[] = {45, 12, 89, 12, 34, 45, 78, 45};
    
    int size = sizeof(data1) / sizeof(data1[0]);

    // Test Hashing Approach (Preserves original array order)
    find_duplicates_hash(data1, size);

    // Test Sorting Approach (Mutates array order)
    find_duplicates_sort(data2, size);

    return 0;
}
