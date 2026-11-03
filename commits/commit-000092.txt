/*
 * Program 92: Search and Count Nodes in Linked List
 * Topic: Linked List Traversal
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int getLength(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int main(void) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 100;
    head->next = NULL;
    printf("Length: %d\n", getLength(head));
    free(head);
    return 0;
}
