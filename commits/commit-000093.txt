/*
 * Program 93: Reverse a Singly Linked List In-Place
 * Topic: Pointer Reversal
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(void) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = NULL;

    head = reverse(head);
    printf("New head: %d\n", head->data);
    free(head->next);
    free(head);
    return 0;
}
