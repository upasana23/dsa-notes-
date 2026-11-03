
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
};

struct Product products[MAX];
int count = 0;

// Add product
void addProduct() {
    if (count >= MAX) {
        printf("Inventory is full!\n");
        return;
    }

    int id;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Product ID already exists!\n");
            return;
        }
    }

    products[count].id = id;

    printf("Enter Product Name: ");
    scanf(" %49[^\n]", products[count].name);

    printf("Enter Category: ");
    scanf(" %29[^\n]", products[count].category);

    printf("Enter Price: ");
    scanf("%f", &products[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &products[count].quantity);

    if (products[count].price < 0 ||
        products[count].quantity < 0) {
        printf("Invalid price or quantity!\n");
        return;
    }

    count++;

    printf("Product added successfully!\n");
}

// Display all products
void displayProducts() {
    if (count == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n========== INVENTORY ==========\n");

    printf("%-8s %-20s %-15s %-10s %-10s\n",
           "ID", "Name", "Category", "Price", "Quantity");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-15s %-10.2f %-10d\n",
               products[i].id,
               products[i].name,
               products[i].category,
               products[i].price,
               products[i].quantity);
    }
}

// Linear search by ID
int linearSearch(int id, int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < count; i++) {
        (*comparisons)++;

        if (products[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Sort products by ID
void sortProducts() {
    struct Product temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].id > products[j + 1].id) {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

// Binary search by ID
int binarySearch(int id, int *comparisons) {
    int low = 0;
    int high = count - 1;

    *comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (products[mid].id == id) {
            return mid;
        }
        else if (products[mid].id < id) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

// Search by product ID
void searchByID() {
    int id, comparisons;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    int index = linearSearch(id, &comparisons);

    if (index != -1) {
        printf("\nProduct Found!\n");
        printf("ID: %d\n", products[index].id);
        printf("Name: %s\n", products[index].name);
        printf("Category: %s\n", products[index].category);
        printf("Price: %.2f\n", products[index].price);
        printf("Quantity: %d\n", products[index].quantity);
    }
    else {
        printf("Product not found!\n");
    }

    printf("Linear Search Comparisons: %d\n", comparisons);
}

// Search by product name
void searchByName() {
    char name[50];
    int found = 0;

    printf("Enter Product Name: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nProduct Found!\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Category: %s\n", products[i].category);
            printf("Price: %.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);

            found = 1;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

// Filter products by category
void filterByCategory() {
    char category[30];
    int found = 0;

    printf("Enter Category: ");
    scanf(" %29[^\n]", category);

    printf("\nProducts in category: %s\n", category);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].category, category) == 0) {
            printf("ID: %d | Name: %s | Price: %.2f | Quantity: %d\n",
                   products[i].id,
                   products[i].name,
                   products[i].price,
                   products[i].quantity);

            found = 1;
        }
    }

    if (!found) {
        printf("No products found in this category!\n");
    }
}

// Compare linear and binary search
void compareSearch() {
    int id, linearCount, binaryCount;
    clock_t start, end;

    printf("Enter Product ID to compare: ");
    scanf("%d", &id);

    // Linear search timing
    start = clock();

    int linearResult = linearSearch(id, &linearCount);

    end = clock();

    double linearTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    // Sort before binary search
    sortProducts();

    // Binary search timing
    start = clock();

    int binaryResult = binarySearch(id, &binaryCount);

    end = clock();

    double binaryTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n======= SEARCH COMPARISON =======\n");

    printf("Linear Search:\n");
    printf("Result Index: %d\n", linearResult);
    printf("Comparisons: %d\n", linearCount);
    printf("Execution Time: %.8f seconds\n", linearTime);

    printf("\nBinary Search:\n");
    printf("Result Index: %d\n", binaryResult);
    printf("Comparisons: %d\n", binaryCount);
    printf("Execution Time: %.8f seconds\n", binaryTime);
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== INVENTORY SEARCH ENGINE ==========\n");

        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search by Product ID\n");
        printf("4. Search by Product Name\n");
        printf("5. Filter by Category\n");
        printf("6. Compare Linear and Binary Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchByID();
                break;

            case 4:
                searchByName();
                break;

            case 5:
                filterByCategory();
                break;

            case 6:
                compareSearch();
                break;

            case 7:
                printf("Exiting Inventory Search Engine...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
