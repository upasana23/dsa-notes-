/*
 * Program 90: Singly Linked List Insertion at Head and Tail
 * Topic: Linked List Foundations
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertHead(Node* head, int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = head;
    return n;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node* head = NULL;
    head = insertHead(head, 30);
    head = insertHead(head, 20);
    head = insertHead(head, 10);
    printList(head);
    return 0;
}
