#include <stdio.h>

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get the next gap size
int getNextGap(int gap) {
    gap = (gap * 10) / 13;  // Shrink gap by the shrink factor (1.3)
    if (gap < 1) {
        return 1; // Minimum gap should be 1
    }
    return gap;
}

// Function to perform Comb Sort
void combSort(int arr[], int n) {
    int gap = n;  // Initialize the gap size as the size of the array
    int swapped = 1; // To keep track of whether a swap occurred

    printf("Starting Comb Sort...\n");
    while (gap != 1 || swapped == 1) {
        // Find the next gap
        gap = getNextGap(gap);
        printf("\nCurrent gap: %d\n", gap);

        swapped = 0; // Reset swapped to 0 to check if a swap happens

        // Compare all elements with the current gap
        for (int i = 0; i < n - gap; i++) {
            printf("Comparing arr[%d] = %d and arr[%d] = %d\n", i, arr[i], i + gap, arr[i + gap]);
            if (arr[i] > arr[i + gap]) {
                // Swap arr[i] and arr[i + gap]
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                printf("Swapped arr[%d] and arr[%d]\n", i, i + gap);
                swapped = 1; // A swap happened
            }
        }

        // Display the array after the pass
        printf("Array after gap %d pass:\n", gap);
        display(arr, n);
    }
}

int main() {
    int n, i;

    // Get input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    display(arr, n);

    // Call comb sort
    combSort(arr, n);

    printf("\nSorted array:\n");
    display(arr, n);

    return 0;
}
