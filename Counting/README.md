# Counting Sort in C

This repository contains a C program that demonstrates the Counting Sort algorithm. Counting Sort is a non-comparison-based sorting algorithm that sorts an array of integers by counting the occurrences of each element and placing them in the correct positions based on the counts.

## How the Program Works

1. **Input the Array**: The program starts by asking the user to input the size of the array and the elements of the array.

2. **Find the Maximum Value**: The program finds the maximum value in the array, which is used to determine the size of the count array.

3. **Initialize the Count Array**: A count array of size `max + 1` is initialized to zero. This array will be used to store the count of each element in the input array.

4. **Counting Occurrences**: The program iterates over the input array, and for each element, it increments the corresponding index in the count array.

5. **Update Count Array for Positions**: The count array is updated to contain the cumulative count of elements, which helps determine the correct positions of elements in the sorted output array.

6. **Build the Output Array**: Using the count array, the program builds the sorted output array by placing each element from the input array into its correct position.

7. **Copy the Sorted Array Back**: The sorted elements are copied back into the original array.

8. **Display Steps**: The program displays each step of the sorting process using the `display()` function, showing how the count array and output array evolve.

## Program Output

The program displays the sorted array along with step-by-step details of what happens during the sorting process.

### Example Input and Output

**Input**:
```
Enter the value of n: 5
Enter n elements:
4 2 2 8 3
```

**Output**:
```
Original array: 4 2 2 8 3

Counting occurrences of each element:
Incrementing count of 4 -> count[4] = 1
0 0 0 0 1 0 0 0 0 

Incrementing count of 2 -> count[2] = 1
0 0 1 0 1 0 0 0 0 

Incrementing count of 2 -> count[2] = 2
0 0 2 0 1 0 0 0 0 

Incrementing count of 8 -> count[8] = 1
0 0 2 0 1 0 0 0 1 

Incrementing count of 3 -> count[3] = 1
0 0 2 1 1 0 0 0 1 

Updating count array for positions:
Updating count[1] to 0
Updating count[2] to 2
Updating count[3] to 3
Updating count[4] to 4
Updating count[5] to 4
Updating count[6] to 4
Updating count[7] to 4
Updating count[8] to 5

Building output array based on positions:
Placing 3 at position 2
Placing 8 at position 4
Placing 2 at position 1
Placing 2 at position 0
Copying sorted elements back to original array:
Copying 2 to arr[0]
Copying 2 to arr[1]
Copying 3 to arr[2]
Copying 4 to arr[3]
Copying 8 to arr[4]

Sorted array: 2 2 3 4 8
```

## Compilation and Execution

To compile and run the program, use the following commands in a terminal:

```bash
gcc counting_sort.c -o counting_sort
./counting_sort
```

## Key Features

- Step-by-step visualization of the Counting Sort algorithm.
- Shows how the count array is used to sort the elements.
- Demonstrates the algorithm’s efficiency in sorting integers within a known range.

## Limitations

- Counting Sort works efficiently only when the range of the input data (difference between the maximum and minimum values) is not significantly larger than the number of elements.

## Author

This implementation was created by [Prashant K Deshmukh](mailto:prashdesh555@gmail.com) to demonstrate how Counting Sort works in C, with detailed comments and output explanations for educational purposes.

## License

This code is released under the MIT License.
