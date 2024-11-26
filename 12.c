#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum number of books

// Function to perform binary search on an array of book titles
int binarySearch(char books[][30], int n, const char* target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare the middle element with the target
        int cmp = strcmp(books[mid], target);
        if (cmp == 0) {
            return mid;  // Target found at index mid
        }
        if (cmp < 0) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    return -1;  // Target not found
}

int main() {
    char books[MAX][30];  // Array to store book titles
    int n, i;
    char target[30];

    // Input number of books and their titles
    printf("Enter the number of books: ");
    scanf("%d", &n);
    printf("Enter the book titles in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", books[i]);
    }

    // Input the book title to search
    printf("Enter the book title to search: ");
    scanf("%s", target);

    // Perform binary search
    int result = binarySearch(books, n, target);

    // Output the result
    if (result != -1) {
        printf("Book found at index: %d\n", result);
    } else {
        printf("Book not found in the list.\n");
    }

    return 0;
}
