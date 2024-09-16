# Bingo Sort in C

## Overview

Bingo Sort is a simple sorting algorithm that works by repeatedly finding the smallest unsorted element (referred to as "bingo") and placing it in its correct position. The process is repeated until the entire array is sorted. This algorithm is similar to Selection Sort but focuses on handling multiple identical values efficiently.

This implementation of Bingo Sort in C includes detailed `printf` statements and a `display` function to show the progress of the sorting algorithm step by step.

## Features

- Finds the smallest and largest element in the array initially.
- Repeatedly places the smallest (bingo) element in its correct position.
- Handles multiple identical values efficiently.
- Displays the array after every significant operation.

## Algorithm Steps

1. **Find the Minimum and Maximum Values**: Identify the smallest (bingo) and largest values in the array.
2. **Sort the Array**: For each `bingo`, the algorithm places all occurrences of it in their correct positions, and then updates `nextBingo` to the next smallest element.
3. **Repeat Until Sorted**: This process is repeated until all elements are sorted.

## Example Output

For an input array: `[34, 12, 56, 12, 78, 5, 12]`

The output will show the progress of the array being sorted after each pass:

```
Original array:
34 12 56 12 78 5 12 

Array after processing 5:
5 12 56 12 78 34 12 

Array after processing 12:
5 12 12 12 78 34 56 

Array after processing 34:
5 12 12 12 34 78 56 

Array after processing 56:
5 12 12 12 34 56 78 

Final sorted array:
5 12 12 12 34 56 78 
```

## How to Run

1. **Clone or Download** the repository.
2. Compile the code using a C compiler. For example, with GCC:
   ```bash
   gcc -o bingo_sort bingo_sort.c
   ```
3. Run the compiled program:
   ```bash
   ./bingo_sort
   ```

## Code Explanation

### `bingoSort` Function

- **Initialization**: The algorithm starts by finding the smallest and largest values in the array.
- **Sorting Loop**: 
  - The smallest value (`bingo`) is identified, and all occurrences of it are moved to their correct positions in the array.
  - After placing `bingo`, the next smallest value (`nextBingo`) is found, and the process repeats.
- **Array Display**: After each major operation, the array is printed to show the sorting progress.

### `display` Function

A helper function to print the contents of the array after each sorting step.

### `main` Function

The main function initializes an array, calls the `bingoSort` function, and prints the array before and after sorting.

## How It Works

1. **Input the Array**: The user provides an array of integers to be sorted.
2. **Sorting Progress**: The algorithm works by continuously identifying the smallest unsorted element and swapping it to its correct position, printing the array at each step.
3. **Final Output**: Once sorted, the array is displayed in ascending order.

## Complexity

- **Time Complexity**: O(n^2) in the worst case, similar to Selection Sort.
- **Space Complexity**: O(1) because it sorts the array in place.

## License

This project is open source and available under the [MIT License](LICENSE).
