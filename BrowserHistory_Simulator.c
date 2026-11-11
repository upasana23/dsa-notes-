
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Page {
    char url[100];
    struct Page *prev, *next;
};

struct Page *current = NULL;

void visitPage(char url[]) {
    struct Page *newPage = malloc(sizeof(struct Page));

    if (newPage == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newPage->url, url);
    newPage->prev = current;
    newPage->next = NULL;

    if (current != NULL) {
        struct Page *temp = current->next;

        while (temp != NULL) {
            struct Page *next = temp->next;
            free(temp);
            temp = next;
        }

        current->next = newPage;
    }

    current = newPage;
    printf("Visited: %s\n", current->url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page!\n");
    } else {
        current = current->prev;
        printf("Current Page: %s\n", current->url);
    }
}

void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page!\n");
    } else {
        current = current->next;
        printf("Current Page: %s\n", current->url);
    }
}

void displayHistory() {
    struct Page *temp = current;

    if (temp == NULL) {
        printf("History is empty!\n");
        return;
    }

    while (temp->prev != NULL)
        temp = temp->prev;

    printf("\nBrowser History:\n");

    while (temp != NULL) {
        if (temp == current)
            printf("-> %s [Current]\n", temp->url);
        else
            printf("   %s\n", temp->url);

        temp = temp->next;
    }
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n1. Visit Page\n2. Back\n3. Forward\n");
        printf("4. Display History\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%99s", url);
                visitPage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                displayHistory();
                break;

            case 5:
                while (current != NULL) {
                    struct Page *temp = current->prev;
                    free(current);
                    current = temp;
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
