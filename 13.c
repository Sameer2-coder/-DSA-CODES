#include <stdio.h>

#define MAX 100  // Maximum size of the array

// Function for Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    printf("Selection Sort:\n");
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Print the array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Function for Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    printf("Bubble Sort:\n");
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Print the array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Function for Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    printf("Insertion Sort:\n");
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Print the array after each pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Function to print the final sorted array
void printArray(int arr[], int n) {
    printf("Final sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get user input for the array
void inputArray(int arr[], int *n) {
    printf("Enter the number of elements in the array: ");
    scanf("%d", n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int arr[MAX], n;

    // Get user input for the array
    inputArray(arr, &n);

    // Perform all sorting algorithms
    selectionSort(arr, n);
    bubbleSort(arr, n);
    insertionSort(arr, n);

    // Print the final sorted array after all sorting algorithms
    printArray(arr, n);

    return 0;
}