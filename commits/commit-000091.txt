/*
 * Program 91: Singly Linked List Deletion by Value
 * Topic: Pointer Rewiring & free()
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* deleteNode(Node* head, int key) {
    Node *temp = head, *prev = NULL;
    if (temp && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return head;
    prev->next = temp->next;
    free(temp);
    return head;
}

int main(void) {
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    a->data = 1; a->next = b;
    b->data = 2; b->next = NULL;

    a = deleteNode(a, 1);
    printf("Head data after delete: %d\n", a->data);
    free(a);
    return 0;
}
