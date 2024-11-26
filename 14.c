#include <stdio.h>

#define MAX 100  // Maximum size of the array

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray

    int L[MAX], R[MAX];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Print the array after merging
    printf("After merging from %d to %d: ", left, right);
    for (int k = 0; k < right + 1; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // Before pi
        quickSort(arr, pi + 1, high); // After pi

        // Print the array after partitioning
        printf("After partitioning from %d to %d: ", low, high);
        for (int k = 0; k < high + 1; k++) {
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

    // Perform Merge Sort
    printf("Performing Merge Sort...\n");
    mergeSort(arr, 0, n - 1);
    printf("Array sorted using Merge Sort:\n");
    printArray(arr, n);
    
    // Perform Quick Sort on the same array
    printf("Performing Quick Sort...\n");
    quickSort(arr, 0, n - 1);
    printf("Array sorted using Quick Sort:\n");
    printArray(arr, n);

    return 0;
}
