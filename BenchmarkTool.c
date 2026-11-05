
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

// Generate random array
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// Copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Measure sorting time
double measureSort(void (*sortFunction)(int[], int),
                   int arr[], int n) {

    clock_t start = clock();

    sortFunction(arr, n);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Main function
int main() {
    int original[MAX];
    int temp[MAX];

    int sizes[] = {100, 500, 1000, 5000, 10000};
    int totalSizes = 5;

    srand((unsigned int)time(NULL));

    printf("========== ALGORITHM BENCHMARK TOOL ==========\n");

    printf("\nSORTING ALGORITHM COMPARISON\n");

    printf("%-10s %-15s %-15s %-15s\n",
           "Size", "Bubble", "Selection", "Insertion");

    for (int s = 0; s < totalSizes; s++) {

        int n = sizes[s];

        generateArray(original, n);

        double bubbleTime, selectionTime, insertionTime;

        copyArray(original, temp, n);
        bubbleTime = measureSort(bubbleSort, temp, n);

        copyArray(original, temp, n);
        selectionTime = measureSort(selectionSort, temp, n);

        copyArray(original, temp, n);
        insertionTime = measureSort(insertionSort, temp, n);

        printf("%-10d %-15.6f %-15.6f %-15.6f\n",
               n, bubbleTime, selectionTime, insertionTime);
    }

    printf("\nSEARCHING ALGORITHM COMPARISON\n");

    int n = 10000;
    generateArray(original, n);

    // Sort array for binary search
    bubbleSort(original, n);

    int key = original[n / 2];

    clock_t start, end;

    start = clock();
    int linearResult = linearSearch(original, n, key);
    end = clock();

    double linearTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int binaryResult = binarySearch(original, n, key);
    end = clock();

    double binaryTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nLinear Search:\n");
    printf("Index: %d\n", linearResult);
    printf("Time: %.8f seconds\n", linearTime);

    printf("\nBinary Search:\n");
    printf("Index: %d\n", binaryResult);
    printf("Time: %.8f seconds\n", binaryTime);

    return 0;
}
