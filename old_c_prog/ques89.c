/*
 * Program 89: Circular Queue Implementation
 * Topic: Ring Buffer
 */
#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) return;
    if (front == -1) { front = rear = 0; }
    else if (rear == SIZE - 1 && front != 0) { rear = 0; }
    else { rear++; }
    items[rear] = val;
}

int dequeue(void) {
    if (front == -1) return -1;
    int data = items[front];
    if (front == rear) { front = -1; rear = -1; }
    else if (front == SIZE - 1) { front = 0; }
    else { front++; }
    return data;
}

int main(void) {
    enqueue(1); enqueue(2); enqueue(3);
    printf("Dequeued: %d\n", dequeue());
    enqueue(4);
    printf("Dequeued: %d\n", dequeue());
    return 0;
}
