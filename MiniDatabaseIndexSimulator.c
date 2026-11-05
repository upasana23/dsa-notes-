
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Record {
    int id;
    char name[50];
    int age;
    char department[30];
};

struct Record records[MAX];
int count = 0;

// Add record
void addRecord() {
    if (count >= MAX) {
        printf("Database is full!\n");
        return;
    }

    int id;

    printf("Enter Record ID: ");
    scanf("%d", &id);

    // Check duplicate ID
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            printf("Record ID already exists!\n");
            return;
        }
    }

    records[count].id = id;

    printf("Enter Name: ");
    scanf(" %49[^\n]", records[count].name);

    printf("Enter Age: ");
    scanf("%d", &records[count].age);

    printf("Enter Department: ");
    scanf(" %29[^\n]", records[count].department);

    if (records[count].age < 0) {
        printf("Invalid age!\n");
        return;
    }

    count++;

    printf("Record inserted successfully!\n");
}

// Display records
void displayRecords() {
    if (count == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("\n========== DATABASE RECORDS ==========\n");

    printf("%-10s %-20s %-10s %-20s\n",
           "ID", "Name", "Age", "Department");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10d %-20s\n",
               records[i].id,
               records[i].name,
               records[i].age,
               records[i].department);
    }
}

// Sequential Search
int sequentialSearch(int id, int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < count; i++) {
        (*comparisons)++;

        if (records[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Sort records by ID
void sortRecords() {
    struct Record temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (records[j].id > records[j + 1].id) {
                temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

// Binary Search
int binarySearch(int id, int *comparisons) {
    int low = 0;
    int high = count - 1;

    *comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (records[mid].id == id) {
            return mid;
        }

        if (records[mid].id < id) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

// Display individual record
void displayRecord(int index) {
    if (index == -1) {
        printf("Record not found!\n");
        return;
    }

    printf("\nRecord Found!\n");

    printf("ID: %d\n", records[index].id);
    printf("Name: %s\n", records[index].name);
    printf("Age: %d\n", records[index].age);
    printf("Department: %s\n", records[index].department);
}

// Search using sequential search
void searchSequential() {
    int id, comparisons;

    printf("Enter Record ID: ");
    scanf("%d", &id);

    int index = sequentialSearch(id, &comparisons);

    displayRecord(index);

    printf("Sequential Search Comparisons: %d\n",
           comparisons);
}

// Search using binary search
void searchBinary() {
    int id, comparisons;

    printf("Enter Record ID: ");
    scanf("%d", &id);

    // Binary search requires sorted records
    sortRecords();

    int index = binarySearch(id, &comparisons);

    displayRecord(index);

    printf("Binary Search Comparisons: %d\n",
           comparisons);
}

// Compare searching methods
void compareSearch() {
    int id;
    int sequentialCount;
    int binaryCount;

    printf("Enter Record ID to search: ");
    scanf("%d", &id);

    // Sequential search on original records
    int sequentialResult =
        sequentialSearch(id, &sequentialCount);

    // Sort records before binary search
    sortRecords();

    int binaryResult =
        binarySearch(id, &binaryCount);

    printf("\n========== SEARCH COMPARISON ==========\n");

    printf("\nSequential Search:\n");
    printf("Result Index: %d\n", sequentialResult);
    printf("Comparisons: %d\n", sequentialCount);

    printf("\nSorted Array + Binary Search:\n");
    printf("Result Index: %d\n", binaryResult);
    printf("Comparisons: %d\n", binaryCount);

    printf("\nNote: Binary Search requires sorted records.\n");
    printf("Sorting time is not included in the search comparison.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== MINI DATABASE INDEX SIMULATOR ==========\n");

        printf("1. Insert Record\n");
        printf("2. Display All Records\n");
        printf("3. Sequential Search\n");
        printf("4. Binary Search\n");
        printf("5. Compare Searching Methods\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;

            case 2:
                displayRecords();
                break;

            case 3:
                searchSequential();
                break;

            case 4:
                searchBinary();
                break;

            case 5:
                compareSearch();
                break;

            case 6:
                printf("Exiting Database Simulator...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
