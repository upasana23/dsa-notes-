/*
 * Program 87: Stack Implementation Using Static Array
 * Topic: LIFO Data Structure
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }
bool isFull(Stack* s) { return s->top == MAX - 1; }
bool isEmpty(Stack* s) { return s->top == -1; }

void push(Stack* s, int val) {
    if (!isFull(s)) s->items[++s->top] = val;
}

int pop(Stack* s) {
    if (!isEmpty(s)) return s->items[s->top--];
    return -1;
}

int main(void) {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    return 0;
}
