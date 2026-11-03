/*
 * Program 94: Doubly Linked List Node Creation
 * Topic: Bidirectional Links
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

int main(void) {
    DNode* n1 = (DNode*)malloc(sizeof(DNode));
    DNode* n2 = (DNode*)malloc(sizeof(DNode));

    n1->data = 10; n1->prev = NULL; n1->next = n2;
    n2->data = 20; n2->prev = n1;   n2->next = NULL;

    printf("Forward: %d -> %d\n", n1->data, n1->next->data);
    printf("Backward: %d -> %d\n", n2->data, n2->prev->data);

    free(n2);
    free(n1);
    return 0;
}
