/*
 * Program 81: Enumerations (enum) in C
 * Topic: Enums & State Management
 */
#include <stdio.h>

typedef enum {
    STATUS_IDLE,
    STATUS_RUNNING,
    STATUS_SUCCESS,
    STATUS_ERROR
} Status;

int main(void) {
    Status current = STATUS_RUNNING;
    if (current == STATUS_RUNNING) {
        printf("Task is currently running.\n");
    }
    return 0;
}
