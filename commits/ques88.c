/*
 * Program 88: Queue Implementation Using Array
 * Topic: FIFO Data Structure
 */
#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void init(Queue* q) { q->front = 0; q->rear = -1; }

void enqueue(Queue* q, int val) {
    if (q->rear < MAX - 1) {
        q->data[++q->rear] = val;
    }
}

int dequeue(Queue* q) {
    if (q->front <= q->rear) {
        return q->data[q->front++];
    }
    return -1;
}

int main(void) {
    Queue q;
    init(&q);
    enqueue(&q, 100);
    enqueue(&q, 200);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
