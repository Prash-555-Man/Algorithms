#include <stdio.h>

// Function to display the array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform Bingo Sort
void bingoSort(int arr[], int size) {
    // Finding the smallest and largest elements from the array
    int bingo = arr[0];
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < bingo) {
            bingo = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    int nextBingo = largest;
    int nextPos = 0;

    while (bingo < nextBingo) {
        // Will keep the track of the element position to be shifted to their correct position
        int startPos = nextPos;
        for (int i = startPos; i < size; i++) {
            if (arr[i] == bingo) {
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[nextPos];
                arr[nextPos] = temp;
                nextPos++;
            } else if (arr[i] < nextBingo) {
                nextBingo = arr[i];
            }
        }

        // Update bingo and nextBingo for the next pass
        bingo = nextBingo;
        nextBingo = largest;
        
        // Display the array after each pass
        printf("Array after processing %d:\n", bingo);
        display(arr, size);
    }

    // Final sorted array
    printf("Final sorted array:\n");
    display(arr, size);
}

// Main function to test Bingo Sort
int main() {
    int arr[] = {34, 12, 56, 12, 78, 5, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    display(arr, size);

    bingoSort(arr, size);

    return 0;
}
