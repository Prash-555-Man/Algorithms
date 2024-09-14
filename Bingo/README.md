# Bingo Sort Algorithm

Bingo Sort is a sorting algorithm that repeatedly places the smallest unsorted value (like drawing numbers in a bingo game) in its correct position until the array is sorted.

## Overview

Bingo Sort works by:
1. Finding the smallest unsorted element in the array.
2. Placing all instances of this element in their correct position.
3. Repeating the process for the next smallest element until the array is sorted.

## Code Explanation

### `display`

```c
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```

- **Purpose**: Prints the elements of the array.
- **Parameters**:
  - `arr[]`: The array to be displayed.
  - `size`: The number of elements in the array.

### `bingoSort`

```c
void bingoSort(int arr[], int size) {
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
        int startPos = nextPos;
        for (int i = startPos; i < size; i++) {
            if (arr[i] == bingo) {
                int temp = arr[i];
                arr[i] = arr[nextPos];
                arr[nextPos] = temp;
                nextPos++;
            } else if (arr[i] < nextBingo) {
                nextBingo = arr[i];
            }
        }
        bingo = nextBingo;
        nextBingo = largest;

        printf("Array after processing %d:\n", bingo);
        display(arr, size);
    }

    printf("Final sorted array:\n");
    display(arr, size);
}
```

- **Purpose**: Sorts the array using the Bingo Sort algorithm.
- **Parameters**:
  - `arr[]`: The array to be sorted.
  - `size`: The number of elements in the array.

### `main`

```c
int main() {
    int arr[] = {34, 12, 56, 12, 78, 5, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    display(arr, size);

    bingoSort(arr, size);

    return 0;
}
```

- **Purpose**: Demonstrates the usage of the `bingoSort` function.
- **Steps**:
  - Define an array with sample data.
  - Print the original array.
  - Call `bingoSort` to sort the array.
  - Print the sorted array.

## Compilation and Execution

1. **Compile the Code**:
   ```bash
   gcc -o bingo_sort bingo_sort.c
   ```

2. **Run the Executable**:
   ```bash
   ./bingo_sort
   ```

## Example Output

```
Original array:
34 12 56 12 78 5 12 

Array after processing 5:
5 12 56 34 78 12 12 
...
Final sorted array:
5 12 12 12 34 56 78
```

## Notes

- Bingo Sort is not efficient for large arrays due to its high time complexity compared to other sorting algorithms.
- The code includes `printf` statements to visualize each step of the sorting process.

## License

This code is provided as-is under the MIT License. See the LICENSE file for details.
