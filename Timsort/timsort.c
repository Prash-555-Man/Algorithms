#include <stdio.h>
#define RUN 50

// Function to display the array at different stages
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform Insertion Sort on a small array
void insertionSort(int arr[], int left, int right) {
    printf("\nPerforming Insertion Sort from index %d to %d\n", left, right);
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;

        // Display the array after each insertion sort pass
        printf("Array after inserting element at index %d:\n", i);
        display(arr, right + 1);
    }
}

// Merge function to merge two sorted halves
void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    // Copy data into left and right subarrays
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    // Merging the left and right subarrays
    printf("\nMerging arrays from index %d to %d:\n", l, r);
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    // Copy remaining elements of left[], if any
    while (i < len1) {
        arr[k++] = left[i++];
    }
    // Copy remaining elements of right[], if any
    while (j < len2) {
        arr[k++] = right[j++];
    }
    // Display the merged array
    printf("Array after merging: ");
    display(arr, r + 1);
}

// Function to implement TimSort
void timSort(int arr[], int n) {
    // Sort small subarrays using Insertion Sort
    for (int i = 0; i < n; i += RUN) {
        int right = (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1);
        insertionSort(arr, i, right);
    }

    // Merge sorted subarrays
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = (left + size - 1) < (n - 1) ? (left + size - 1) : (n - 1);
            int right = (left + 2 * size - 1) < (n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Main function to demonstrate TimSort
int main() {
    int n, i;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    display(arr, n);

    timSort(arr, n);

    printf("\nFinal sorted array:\n");
    display(arr, n);

    return 0;
}
