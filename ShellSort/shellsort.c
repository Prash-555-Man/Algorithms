#include <stdio.h>

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Shell Sort function
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        printf("\nSorting with gap = %d\n", gap);

        // Perform gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;

            // Display the array after each gap insertion
            printf("Array after inserting element at index %d:\n", i);
            display(arr, n);
        }
    }
}

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

    // Display the original array
    printf("\nOriginal array:\n");
    display(arr, n);

    // Perform Shell Sort
    shellSort(arr, n);

    // Display the final sorted array
    printf("\nFinal sorted array:\n");
    display(arr, n);

    return 0;
}
