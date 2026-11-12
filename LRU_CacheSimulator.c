
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
#define HASH_SIZE 10

struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
};

struct Node *hashTable[HASH_SIZE];

struct Node *head = NULL;
struct Node *tail = NULL;
int cacheSize = 0;

int hashFunction(int key) {
    int index = key % HASH_SIZE;

    if (index < 0)
        index += HASH_SIZE;

    return index;
}

struct Node *search(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key)
            return temp;

        temp = temp->hashNext;
    }

    return NULL;
}
