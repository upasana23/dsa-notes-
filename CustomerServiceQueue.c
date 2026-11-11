
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Customer {
    int id;
    char name[50];
    int priority;
};

struct Customer queue[MAX];
int count = 0;

void addCustomer() {
    if (count == MAX) {
        printf("Queue is full!\n");
        return;
    }

    struct Customer c;

    printf("Enter Customer ID: ");
    scanf("%d", &c.id);

    printf("Enter Customer Name: ");
    scanf("%49s", c.name);

    printf("Enter Priority (1=High, 2=Normal): ");
    scanf("%d", &c.priority);

    if (c.priority != 1 && c.priority != 2) {
        printf("Invalid priority!\n");
        return;
    }

    queue[count++] = c;
    printf("Customer added successfully!\n");
}

void serveCustomer() {
    if (count == 0) {
        printf("No customers waiting!\n");
        return;
    }

    int pos = 0;

    // Find the first customer with the highest priority
    for (int i = 1; i < count; i++) {
        if (queue[i].priority < queue[pos].priority) {
            pos = i;
        }
    }

    printf("\nServing Customer:\n");
    printf("ID: %d\n", queue[pos].id);
    printf("Name: %s\n", queue[pos].name);

    for (int i = pos; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;
}

void displayQueue() {
    if (count == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\nPending Customers:\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Priority: %s\n",
               queue[i].id,
               queue[i].name,
               queue[i].priority == 1 ? "High" : "Normal");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Customer\n2. Serve Customer\n");
        printf("3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
