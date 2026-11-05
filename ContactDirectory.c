
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *head = NULL;

// Search contact by ID
struct Contact *findContact(int id) {
    struct Contact *temp = head;

    while (temp != NULL) {
        if (temp->id == id)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Add contact
void addContact() {
    struct Contact *newNode;
    struct Contact *temp;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Contact ID: ");
    scanf("%d", &newNode->id);

    if (findContact(newNode->id) != NULL) {
        printf("Contact ID already exists!\n");
        free(newNode);
        return;
    }

    printf("Enter Name: ");
    scanf(" %49[^\n]", newNode->name);

    printf("Enter Phone Number: ");
    scanf("%14s", newNode->phone);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Contact added successfully!\n");
}

// Display contacts
void displayContacts() {
    struct Contact *temp = head;

    if (head == NULL) {
        printf("Contact directory is empty!\n");
        return;
    }

    printf("\n========== CONTACT DIRECTORY ==========\n");

    while (temp != NULL) {
        printf("\nID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);

        temp = temp->next;
    }
}

// Search contact by name
void searchContact() {
    char name[50];
    int found = 0;

    struct Contact *temp = head;

    printf("Enter contact name: ");
    scanf(" %49[^\n]", name);

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\nContact Found!\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);

            found = 1;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Update contact
void updateContact() {
    int id;

    printf("Enter Contact ID to update: ");
    scanf("%d", &id);

    struct Contact *temp = findContact(id);

    if (temp == NULL) {
        printf("Contact not found!\n");
        return;
    }

    printf("Enter New Name: ");
    scanf(" %49[^\n]", temp->name);

    printf("Enter New Phone Number: ");
    scanf("%14s", temp->phone);

    printf("Contact updated successfully!\n");
}

// Delete contact
void deleteContact() {
    int id;

    printf("Enter Contact ID to delete: ");
    scanf("%d", &id);

    struct Contact *temp = head;
    struct Contact *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    free(temp);

    printf("Contact deleted successfully!\n");
}

// Free all memory
void freeContacts() {
    struct Contact *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== CONTACT DIRECTORY ==========\n");

        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                updateContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                freeContacts();
                printf("Exiting Contact Directory...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
