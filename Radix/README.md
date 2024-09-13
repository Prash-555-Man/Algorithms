# Radix Sort with Debugging

This program demonstrates the Radix Sort algorithm for sorting integers. The implementation includes detailed debugging information to help understand the steps of the sorting process. 

## Overview

Radix Sort is a non-comparative integer sorting algorithm. It sorts numbers by processing individual digits. Numbers are processed from the least significant digit to the most significant digit.

## Features

- **Counting Sort for Radix**: Utilizes Counting Sort as a subroutine to sort elements based on each digit.
- **Debugging Output**: Detailed `printf` statements are included to trace each step of the sorting process, including occurrences of digits, updating positions, and building the output array.

## How It Works

1. **Input Reading**: The program reads the number of elements and the elements themselves from the user.
2. **Display Original Array**: The original unsorted array is displayed.
3. **Radix Sort**: 
   - Determines the maximum value to figure out the number of digits.
   - Sorts the array by each digit starting from the least significant digit (units place) to the most significant digit.
   - Utilizes Counting Sort for each digit position.
4. **Display Sorted Array**: After sorting, the sorted array is displayed.

## Functions

- `display(int arr[], int n)`: Prints the array elements.
- `getMax(int arr[], int n)`: Finds the maximum value in the array.
- `countingSortForRadix(int arr[], int n, int exp)`: Performs Counting Sort for a specific digit.
- `radixSort(int arr[], int n)`: Main function to sort the array using Radix Sort.

## Example

### Input
```
Enter the value of n: 8
Enter n elements:
170 45 75 90 802 24 2 66
```

### Output
```
Original array: 170 45 75 90 802 24 2 66 

Sorting by digit with exp = 1:

Counting occurrences of digits for exp = 1:
Incrementing count[0] -> count[0] = 1
Incrementing count[5] -> count[5] = 1
Incrementing count[7] -> count[7] = 1
Incrementing count[0] -> count[0] = 2
Incrementing count[2] -> count[2] = 1
Incrementing count[6] -> count[6] = 1
Incrementing count[0] -> count[0] = 3
Incrementing count[9] -> count[9] = 1

All: 3 0 1 0 0 1 1 1 0 1

Updating count array for positions:
Updating count[1] to 3
Updating count[2] to 4
Updating count[3] to 4
Updating count[4] to 4
Updating count[5] to 5
Updating count[6] to 6
Updating count[7] to 7
Updating count[8] to 7
Updating count[9] to 8

All: 3 4 4 4 5 6 7 7 7 8

Building output array based on positions for exp = 1:
Placing 2 at position 0
Placing 24 at position 1
Placing 45 at position 2
Placing 66 at position 3
Placing 75 at position 4
Placing 90 at position 5
Placing 170 at position 6
Placing 802 at position 7

All: 2 24 45 66 75 90 170 802

Copying sorted elements back to the original array for exp = 1:
Copying 2 to arr[0]
Copying 24 to arr[1]
Copying 45 to arr[2]
Copying 66 to arr[3]
Copying 75 to arr[4]
Copying 90 to arr[5]
Copying 170 to arr[6]
Copying 802 to arr[7]

Sorted array: 2 24 45 66 75 90 170 802
```

## Compilation and Execution

1. **Compile**: Use a C compiler like `gcc`:
   ```bash
   gcc -o radix_sort radix_sort.c
   ```
2. **Run**: Execute the compiled program:
   ```bash
   ./radix_sort
   ```

## Notes

- The program uses dynamic memory allocation for the buckets in the bucket sort implementation. Ensure you have enough memory to handle the array and bucket sizes.
- The debugging outputs are verbose and meant for educational purposes. Remove or comment out the `printf` statements for production use.
