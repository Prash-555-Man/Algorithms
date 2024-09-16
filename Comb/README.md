# Comb Sort Algorithm in C

## Overview

**Comb Sort** is an improvement over the traditional Bubble Sort algorithm. It eliminates small values (often referred to as "turtles") from the end of the array by introducing a `gap` between elements to be compared. The gap is progressively reduced by a factor (commonly 1.3) until it becomes 1, at which point the algorithm behaves like Bubble Sort.

This repository contains a C implementation of the Comb Sort algorithm with detailed step-by-step output using `printf()` and a `display()` function to visualize the sorting process.

## Features

- **Comb Sort Algorithm**: A hybrid sorting algorithm that efficiently handles "turtles."
- **Dynamic Gap Calculation**: Reduces the gap by a shrink factor of 1.3 after each pass.
- **Detailed Output**: Displays the array at each stage of the sorting process, showing swaps and gap adjustments.
- **Minimal Time Complexity**: Average case performance of Comb Sort is \(O(n \log n)\), which is faster than Bubble Sort's \(O(n^2)\).

## How it Works

1. **Initial Setup**: 
   - The algorithm starts by calculating the initial gap size as the length of the array.
   - A `while` loop is used to continually reduce the gap by dividing it by 1.3 until the gap reaches 1.

2. **Comparison and Swapping**:
   - For each gap, the algorithm compares elements that are separated by the current gap size.
   - If elements are in the wrong order (i.e., the first element is larger than the second), they are swapped.

3. **Gap Reduction**:
   - The gap is recalculated by dividing the current gap by 1.3.
   - The process continues until the gap becomes 1, at which point it behaves like Bubble Sort and finishes sorting the array.

## Usage

### Requirements

- GCC Compiler (for compiling the C program)
- Basic understanding of C programming language

### How to Run

1. Clone the repository or download the source code.
   
2. Open a terminal and navigate to the directory where the source code is located.

3. Compile the program using `gcc`:

   ```bash
   gcc -o comb_sort comb_sort.c
   ```

4. Run the program:

   ```bash
   ./comb_sort
   ```

5. Input the number of elements and the array you wish to sort.

### Example

Sample input:
```
Enter the number of elements in the array: 10
Enter 10 elements:
10 9 3 7 6 5 4 2 1 8
```

Output:
```
Original array:
10 9 3 7 6 5 4 2 1 8 

Starting Comb Sort...

Current gap: 7
Comparing arr[0] = 10 and arr[7] = 2
Swapped arr[0] and arr[7]
...

Sorted array:
1 2 3 4 5 6 7 8 9 10
```

### Program Explanation

- **getNextGap()**: This function calculates the next gap by shrinking the current gap by a factor of 1.3. If the gap becomes less than 1, it is set to 1.
  
- **combSort()**: The main function that implements Comb Sort.
  - It uses a loop that continues until both the gap is 1 and no swaps occur during a full pass.
  - It calls the `display()` function after each pass to show the current state of the array.

- **display()**: This function prints the current state of the array to the console.

## Time Complexity

- **Best Case**: \(O(n \log n)\)
- **Average Case**: \(O(n \log n)\)
- **Worst Case**: \(O(n^2)\)

The performance improves on average compared to Bubble Sort, especially for large datasets.

## License

This project is licensed under the MIT License.
