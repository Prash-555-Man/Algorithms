# Radix Sort in C

This project demonstrates the **Radix Sort** algorithm in C with detailed debug information to help understand the internal steps of sorting. Radix Sort is a non-comparative sorting algorithm that processes numbers digit by digit, sorting based on the individual digits from the least significant to the most significant.

## How It Works

Radix Sort works by sorting the input numbers based on each digit, starting from the least significant digit (LSD) to the most significant digit (MSD). The sorting of each digit is done using **Counting Sort**, a stable sorting algorithm that works in linear time.

### Steps Involved:

1. **Find the maximum number**: The number of digits in the largest number determines how many passes the algorithm will perform.
2. **Sort by each digit**: Starting with the least significant digit, use Counting Sort to arrange numbers based on that digit. Repeat this process for each digit, moving towards the most significant digit.
3. **Display intermediate steps**: At each pass, the algorithm prints debug information showing the counting of digits, the updated positions, and the building of the sorted array.

## Code Structure

- **`display(int arr[], int n)`**: Prints the elements of the array.
- **`getMax(int arr[], int n)`**: Returns the maximum element in the array.
- **`countingSortForRadix(int arr[], int n, int exp)`**: Performs Counting Sort on the array based on the digit represented by `exp`.
- **`radixSort(int arr[], int n)`**: Coordinates the overall sorting process by repeatedly calling `countingSortForRadix`.
- **`main()`**: The entry point, takes input from the user, displays the original array, sorts it using Radix Sort, and prints the final sorted array.

## Example

### Input:
```
Enter the value of n: 6
Enter n elements:
170 45 75 90 802 24
```

### Output:
```
Enter the value of n: 6
Enter n elements:
170
45
75
90
802
24


Original array: 
170 45 75 90 802 24 

Sorting by digit with exp = 1:

Counting occurrences of digits for exp = 1:
Incrementing count[0] -> count[0] = 1
Incrementing count[5] -> count[5] = 1
Incrementing count[5] -> count[5] = 2
Incrementing count[0] -> count[0] = 2
Incrementing count[2] -> count[2] = 1
Incrementing count[4] -> count[4] = 1

All: 
2 0 1 0 1 2 0 0 0 0 


Updating count array for positions:
Updating count[1] to 2
Updating count[2] to 3
Updating count[3] to 3
Updating count[4] to 4
Updating count[5] to 6
Updating count[6] to 6
Updating count[7] to 6
Updating count[8] to 6
Updating count[9] to 6

All: 
2 2 3 3 4 6 6 6 6 6 


Building output array based on positions for exp = 1:
Placing 24 at position 3
Placing 802 at position 2
Placing 90 at position 1
Placing 75 at position 5
Placing 45 at position 4
Placing 170 at position 0

All: 
170 90 802 24 45 75 

Copying sorted elements back to the original array for exp = 1:
Copying 170 to arr[0]
170 90 802 24 45 75 

Copying 90 to arr[1]
170 90 802 24 45 75 

Copying 802 to arr[2]
170 90 802 24 45 75 

Copying 24 to arr[3]
170 90 802 24 45 75 

Copying 45 to arr[4]
170 90 802 24 45 75 

Copying 75 to arr[5]
170 90 802 24 45 75 


Sorting by digit with exp = 10:

Counting occurrences of digits for exp = 10:
Incrementing count[7] -> count[7] = 1
Incrementing count[9] -> count[9] = 1
Incrementing count[0] -> count[0] = 1
Incrementing count[2] -> count[2] = 1
Incrementing count[4] -> count[4] = 1
Incrementing count[7] -> count[7] = 2

All: 
1 0 1 0 1 0 0 2 0 1 


Updating count array for positions:
Updating count[1] to 1
Updating count[2] to 2
Updating count[3] to 2
Updating count[4] to 3
Updating count[5] to 3
Updating count[6] to 3
Updating count[7] to 5
Updating count[8] to 5
Updating count[9] to 6

All: 
1 1 2 2 3 3 3 5 5 6 


Building output array based on positions for exp = 10:
Placing 75 at position 4
Placing 45 at position 3
Placing 24 at position 2
Placing 802 at position 0
Placing 90 at position 5
Placing 170 at position 1

All: 
802 170 24 45 75 90 

Copying sorted elements back to the original array for exp = 10:
Copying 802 to arr[0]
802 90 802 24 45 75 

Copying 170 to arr[1]
802 170 802 24 45 75 

Copying 24 to arr[2]
802 170 24 24 45 75 

Copying 45 to arr[3]
802 170 24 45 45 75 

Copying 75 to arr[4]
802 170 24 45 75 75 

Copying 90 to arr[5]
802 170 24 45 75 90 


Sorting by digit with exp = 100:

Counting occurrences of digits for exp = 100:
Incrementing count[8] -> count[8] = 1
Incrementing count[1] -> count[1] = 1
Incrementing count[0] -> count[0] = 1
Incrementing count[0] -> count[0] = 2
Incrementing count[0] -> count[0] = 3
Incrementing count[0] -> count[0] = 4

All: 
4 1 0 0 0 0 0 0 1 0 


Updating count array for positions:
Updating count[1] to 5
Updating count[2] to 5
Updating count[3] to 5
Updating count[4] to 5
Updating count[5] to 5
Updating count[6] to 5
Updating count[7] to 5
Updating count[8] to 6
Updating count[9] to 6

All: 
4 5 5 5 5 5 5 5 6 6 


Building output array based on positions for exp = 100:
Placing 90 at position 3
Placing 75 at position 2
Placing 45 at position 1
Placing 24 at position 0
Placing 170 at position 4
Placing 802 at position 5

All: 
24 45 75 90 170 802 

Copying sorted elements back to the original array for exp = 100:
Copying 24 to arr[0]
24 170 24 45 75 90 

Copying 45 to arr[1]
24 45 24 45 75 90 

Copying 75 to arr[2]
24 45 75 45 75 90 

Copying 90 to arr[3]
24 45 75 90 75 90 

Copying 170 to arr[4]
24 45 75 90 170 90 

Copying 802 to arr[5]
24 45 75 90 170 802 

Sorted array: 
24 45 75 90 170 802

```

## How to Run

1. Clone the repository or copy the source code into a `.c` file.
2. Compile the code using a C compiler:
   ```
   gcc radix_sort.c -o radix_sort
   ```
3. Run the executable:
   ```
   ./radix_sort
   ```

## Key Features

- **Stable Sorting**: Radix Sort preserves the order of numbers with equal digits.
- **Non-Comparative**: Unlike Quick Sort or Merge Sort, Radix Sort doesn't compare the elements directly.
- **Efficient for large numbers**: Especially useful when the number of digits is small relative to the number of elements.

## Complexity

- **Time Complexity**: O(d * (n + k)) where:
  - `d` is the number of digits in the largest number.
  - `n` is the number of elements in the array.
  - `k` is the range of digit values (0-9 for decimal numbers).
- **Space Complexity**: O(n + k) due to the temporary `count` and `output` arrays.

## Debug Information

This implementation includes detailed debugging output to help visualize:
- How the algorithm counts occurrences of digits.
- How it updates positions for the current digit.
- How it builds the output array at each pass.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
