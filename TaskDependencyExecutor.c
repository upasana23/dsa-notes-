
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int indegree[MAX];
int tasks[MAX];
int n;

void addDependency(int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n) {
        printf("Invalid task number!\n");
        return;
    }

    if (from == to) {
        printf("A task cannot depend on itself!\n");
        return;
    }

    if (graph[from][to] == 0) {
        graph[from][to] = 1;
        indegree[to]++;
        printf("Dependency added successfully!\n");
    } else {
        printf("Dependency already exists!\n");
    }
}

void executeTasks() {
    int queue[MAX];
    int front = 0, rear = -1;
    int processed = 0;

    int degree[MAX];

    for (int i = 0; i < n; i++) {
        degree[i] = indegree[i];

        if (degree[i] == 0)
            queue[++rear] = i;
    }

    printf("\nTask Execution Order:\n");

    while (front <= rear) {
        int current = queue[front++];

        printf("Task %d executed\n", tasks[current]);
        processed++;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1) {
                degree[i]--;

                if (degree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (processed != n) {
        printf("\nCircular dependency detected!\n");
        printf("Some tasks cannot be executed.\n");
    } else {
        printf("\nAll tasks executed successfully!\n");
    }
}

void displayDependencies() {
    printf("\nTask Dependencies:\n");

    for (int i = 0; i < n; i++) {
        printf("Task %d depends on: ", tasks[i]);

        int found = 0;

        for (int j = 0; j < n; j++) {
            if (graph[j][i] == 1) {
                printf("%d ", tasks[j]);
                found = 1;
            }
        }

        if (!found)
            printf("None");

        printf("\n");
    }
}

int main() {
    int choice, from, to;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of tasks!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        tasks[i] = i + 1;

    while (1) {
        printf("\n1. Add Dependency\n");
        printf("2. Display Dependencies\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter prerequisite task and dependent task: ");
                scanf("%d %d", &from, &to);

                addDependency(from - 1, to - 1);
                break;

            case 2:
                displayDependencies();
                break;

            case 3:
                executeTasks();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
