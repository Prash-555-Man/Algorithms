#include <stdio.h>

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

// Function to find the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort based on the digit represented by exp
void countingSortForRadix(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Count array for digits (0-9)

    // Store count of occurrences of each digit
    printf("Counting occurrences of digits for exp = %d:\n", exp);
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        printf("Incrementing count[%d] -> count[%d] = %d\n", (arr[i] / exp) % 10, (arr[i] / exp) % 10, count[(arr[i] / exp) % 10]);
    }
    printf("\nAll: ");
    display(count, 10);

    // Update count array to have the actual positions
    printf("\nUpdating count array for positions:\n");
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        printf("Updating count[%d] to %d\n", i, count[i]);
    }
    printf("\nAll: ");
    display(count, 10);

    // Build the output array
    printf("\nBuilding output array based on positions for exp = %d:\n", exp);
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        printf("Placing %d at position %d\n", arr[i], count[index] - 1);
        count[index]--;
    }
    printf("\nAll: ");
    display(output, n);

    // Copy the sorted elements back into the original array
    printf("Copying sorted elements back to the original array for exp = %d:\n", exp);
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        printf("Copying %d to arr[%d]\n", output[i], i);
        display(arr, n);
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        printf("\nSorting by digit with exp = %d:\n\n", exp);
        countingSortForRadix(arr, n, exp);
    }
}

// Main function to demonstrate Radix Sort
int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter n elements:\n");
    for (i=0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n\nOriginal array: ");
    display(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}
