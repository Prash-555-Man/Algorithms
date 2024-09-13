
#include <stdio.h>
#include <string.h>

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int max = findMax(arr, n);
    int count[max + 1];  // Create a count array with size max+1
    int output[n];       // Output array to store sorted elements

    // Initialize count array to zero
    memset(count, 0, sizeof(count));
    // Store the count of each element
    printf("\nCounting occurrences of each element:\n");
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        printf("Incrementing count of %d -> count[%d] = %d\n", arr[i], arr[i], count[arr[i]]);
        display(count, max + 1);
    }

    // Update count array to contain the position of elements
    printf("\nUpdating count array for positions:\n");
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
        printf("Updating count[%d] to %d\n", i, count[i]);
        display(count, max + 1);
    }

    // Build the output array
    printf("\nBuilding output array based on positions:\n");
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        printf("Placing %d at position %d\n", arr[i], count[arr[i]] - 1);
        count[arr[i]]--;
    }
    display(output, n);

    // Copy the sorted elements into the original array
    printf("\nCopying sorted elements back to original array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        printf("Copying %d to arr[%d]\n", output[i], i);
        display(arr, n);
    }
}

// Main function to demonstrate Counting Sort
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
    printf("Original array: ");
    display(arr, n);

    countingSort(arr, n);

    printf("\nSorted array: ");
    display(arr, n);

    return 0;
}
