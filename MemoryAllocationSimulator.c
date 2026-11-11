
#include <stdio.h>

#define MAX 100
#define MEMORY_SIZE 1000

struct Block {
    int start;
    int size;
    int allocated;
    int id;
};

struct Block blocks[MAX];
int count = 1;
int nextID = 1;

void initialize() {
    blocks[0].start = 0;
    blocks[0].size = MEMORY_SIZE;
    blocks[0].allocated = 0;
    blocks[0].id = -1;
}

void allocateMemory(int request, int strategy) {
    int best = -1;

    if (request <= 0) {
        printf("Invalid memory request!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (!blocks[i].allocated &&
            blocks[i].size >= request) {

            if (best == -1) {
                best = i;
            }
            else if (strategy == 2 &&
                     blocks[i].size < blocks[best].size) {
                best = i;
            }

            if (strategy == 1)
                break;
        }
    }

    if (best == -1) {
        printf("Memory allocation failed!\n");
        return;
    }

    if (blocks[best].size > request) {
        if (count == MAX) {
            printf("Block limit reached!\n");
            return;
        }

        for (int i = count; i > best + 1; i--)
            blocks[i] = blocks[i - 1];

        blocks[best + 1].start =
            blocks[best].start + request;

        blocks[best + 1].size =
            blocks[best].size - request;

        blocks[best + 1].allocated = 0;
        blocks[best + 1].id = -1;

        blocks[best].size = request;
        count++;
    }

    blocks[best].allocated = 1;
    blocks[best].id = nextID++;

    printf("Memory allocated successfully!\n");
    printf("Allocation ID: %d\n", blocks[best].id);
}

void freeMemory(int id) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (blocks[i].allocated && blocks[i].id == id) {
            blocks[i].allocated = 0;
            blocks[i].id = -1;
            found = 1;
            printf("Memory block freed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Invalid allocation ID!\n");
        return;
    }

    // Merge adjacent free blocks
    for (int i = 0; i < count - 1; ) {
        if (!blocks[i].allocated &&
            !blocks[i + 1].allocated) {

            blocks[i].size += blocks[i + 1].size;

            for (int j = i + 1; j < count - 1; j++)
                blocks[j] = blocks[j + 1];

            count--;
        }
        else {
            i++;
        }
    }
}

void displayMemory() {
    printf("\nMemory Status:\n");
    printf("----------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("Start: %d | Size: %d | ",
               blocks[i].start, blocks[i].size);

        if (blocks[i].allocated)
            printf("Allocated | ID: %d\n", blocks[i].id);
        else
            printf("Free\n");
    }

    printf("----------------------------------\n");
}

int main() {
    int choice, request, strategy, id;

    initialize();

    while (1) {
        printf("\n1. Allocate Memory\n");
        printf("2. Free Memory\n");
        printf("3. Display Memory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter memory size: ");
                scanf("%d", &request);

                printf("1. First Fit\n2. Best Fit\n");
                printf("Choose strategy: ");
                scanf("%d", &strategy);

                if (strategy != 1 && strategy != 2) {
                    printf("Invalid strategy!\n");
                    break;
                }

                allocateMemory(request, strategy);
                break;

            case 2:
                printf("Enter Allocation ID: ");
                scanf("%d", &id);
                freeMemory(id);
                break;

            case 3:
                displayMemory();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
