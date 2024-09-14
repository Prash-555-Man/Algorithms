# Shell Sort in C

## Introduction

**Shell Sort** is a highly efficient sorting algorithm that generalizes **Insertion Sort** by allowing the exchange of far-apart elements. It improves the performance of Insertion Sort by comparing elements separated by a gap and gradually reducing this gap, eventually sorting the array.

This implementation of Shell Sort in C provides detailed step-by-step output with `printf()` statements and uses a `display()` function to show the array at different stages of the sorting process.

## How Shell Sort Works

1. **Gap Sequence**: 
   - The algorithm starts with a large gap, usually `n/2`, where `n` is the number of elements in the array.
   - The gap is reduced in each step (`gap /= 2`) until it becomes 1. A gap of 1 is equivalent to a normal Insertion Sort.

2. **Sorting with Gaps**: 
   - For each gap, Shell Sort performs a **gapped insertion sort**: it compares elements that are `gap` positions apart and shifts them to the correct position.

3. **Final Pass**:
   - When the gap is reduced to 1, Shell Sort completes the sorting process using standard Insertion Sort.

## Features

- **Step-by-step Output**: 
  The implementation uses `printf()` statements to print detailed information at each step, including the current gap and the state of the array after each insertion.
  
- **Display Function**: 
  The `display()` function prints the array at various stages, providing a clear visualization of the sorting process.

## Usage

### Compilation and Execution

To compile and run the program, follow these steps:

1. **Compilation**: Use a C compiler like `gcc` to compile the program:
   ```bash
   gcc -o shellsort shellsort.c
   ```

2. **Execution**: Run the compiled executable:
   ```bash
   ./shellsort
   ```

### Input

The program will prompt you to enter the number of elements and the array elements.

Example input:
```
Enter the number of elements: 7
Enter the elements of the array:
12 34 54 2 3 89 11
```

### Output

The program will display the original array, show the sorting process at each gap value, and finally print the sorted array.

Example output:

```
Original array:
12 34 54 2 3 89 11 

Sorting with gap = 3

Array after inserting element at index 3:
2 34 54 12 3 89 11 

Array after inserting element at index 4:
2 3 54 12 34 89 11 

Array after inserting element at index 6:
2 3 11 12 34 89 54 

Sorting with gap = 1

Array after inserting element at index 1:
2 3 11 12 34 89 54 

Array after inserting element at index 2:
2 3 11 12 34 89 54 

Array after inserting element at index 3:
2 3 11 12 34 89 54 

Array after inserting element at index 4:
2 3 11 12 34 89 54 

Array after inserting element at index 5:
2 3 11 12 34 54 89 

Final sorted array:
2 3 11 12 34 54 89 
```

## Code Explanation

1. **display()**: 
   The `display()` function prints the current state of the array. It is called at various stages to show how the array changes over time.

2. **shellSort()**:
   The `shellSort()` function performs the sorting process. It starts with a gap of `n/2` and gradually reduces the gap until it reaches 1. At each gap, the array is sorted using a gapped insertion sort.

3. **Main Function**: 
   The main function handles user input, calls `shellSort()` to sort the array, and displays the original and final sorted arrays.

## Example

Given the input:
```
12 34 54 2 3 89 11
```

The Shell Sort process is as follows:
1. Gap = 3: Elements at indices 0, 3, and 6 are sorted.
   - Array after sorting: `2 3 11 12 34 89 54`
   
2. Gap = 1: The array is fully sorted using standard insertion sort.
   - Final sorted array: `2 3 11 12 34 54 89`

## Conclusion

Shell Sort is an efficient algorithm, particularly for medium-sized arrays. This implementation includes detailed outputs to visualize each step of the sorting process, helping to understand how Shell Sort works internally.

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it.

### Key Points in the README:
- **Introduction**: Describes the algorithm and its functionality.
- **How Shell Sort Works**: Explains the algorithm’s logic.
- **Features**: Highlights the use of `printf()` and `display()` for visual feedback.
- **Usage**: Provides compilation, execution instructions, and example inputs/outputs.
- **Code Explanation**: Breaks down the key functions in the code.
- **Example**: Shows a detailed example with input and output.
