# TimSort Algorithm

## Overview

**TimSort** is a hybrid sorting algorithm that combines **Insertion Sort** and **Merge Sort**. It was designed to perform efficiently on real-world data, which often contains partially sorted runs. This algorithm is used in Python's built-in `sorted()` and `list.sort()` functions, as well as in Java's `Arrays.sort()` for non-primitive types. 

In this implementation, the array is divided into small sections (known as **runs**), which are sorted using **Insertion Sort**. These sorted runs are then merged using a **Merge Sort** technique to produce the final sorted array.

## How TimSort Works

1. **Breaking into Runs**:
   - The input array is divided into smaller runs. Each run is then sorted using **Insertion Sort**, which works efficiently on small arrays.

2. **Merge Sorted Runs**:
   - Once all the runs are sorted, they are merged in pairs using **Merge Sort**.

### Key Concepts:

- **RUN**: A chunk of the array (with a predefined size, typically 32 or 64) that is sorted using Insertion Sort.
  
- **Insertion Sort**: Insertion Sort works well on small arrays or sections of an array. In TimSort, it is used to sort the small RUNs.

- **Merge Sort**: After sorting each run, TimSort merges them using a Merge Sort approach, which ensures that the whole array is sorted correctly.

## Time Complexity

- **Best Case**: O(n) (When the array is already sorted)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

## Space Complexity
- **O(n)** (due to the additional space needed for the temporary arrays during the merging process)

## Example

### Input Array:
```
[5, 21, 7, 23, 19, 10, 14, 3, 27, 8, 16]
```

### Step-by-Step Process:
1. **Step 1**: Break the array into smaller runs (size of `RUN`, which is 50 here).
   
2. **Step 2**: Sort each run using **Insertion Sort**.

3. **Step 3**: Merge the sorted runs using **Merge Sort**.

### Final Output:

```
[3, 5, 7, 8, 10, 14, 16, 19, 21, 23, 27]
```

## Running the Code

The code is implemented in C. You can compile and run the code using a C compiler like `gcc`.

### Compilation

```bash
gcc timsort.c -o timsort
```

### Execution

```bash
./timsort
```

### Sample Output

```text
Original array:
5 21 7 23 19 10 14 3 27 8 16 

Performing Insertion Sort from index 0 to 10
Array after inserting element at index 1:
5 21 7 23 19 10 14 3 27 8 16 
Array after inserting element at index 2:
5 7 21 23 19 10 14 3 27 8 16 
Array after inserting element at index 3:
5 7 21 23 19 10 14 3 27 8 16 
Array after inserting element at index 4:
5 7 19 21 23 10 14 3 27 8 16 
Array after inserting element at index 5:
5 7 10 19 21 23 14 3 27 8 16 
Array after inserting element at index 6:
5 7 10 14 19 21 23 3 27 8 16 
Array after inserting element at index 7:
3 5 7 10 14 19 21 23 27 8 16 
Array after inserting element at index 8:
3 5 7 10 14 19 21 23 27 8 16 
Array after inserting element at index 9:
3 5 7 8 10 14 19 21 23 27 16 
Array after inserting element at index 10:
3 5 7 8 10 14 16 19 21 23 27 

Final sorted array:
3 5 7 8 10 14 16 19 21 23 27 
```

## Functions in the Code

### 1. `insertionSort(int arr[], int left, int right)`
- This function sorts a subarray using **Insertion Sort** from the `left` index to the `right` index.

### 2. `merge(int arr[], int l, int m, int r)`
- This function merges two sorted subarrays. The first subarray is from `l` to `m`, and the second subarray is from `m+1` to `r`.

### 3. `timSort(int arr[], int n)`
- This function implements the TimSort algorithm. It first sorts runs of the array using Insertion Sort and then merges them using the merge function.

### 4. `display(int arr[], int n)`
- This function prints the contents of the array at different stages of sorting.

## Conclusion

TimSort is a highly efficient sorting algorithm for real-world data. It leverages the benefits of both Insertion Sort and Merge Sort, making it particularly good for partially sorted data. This README explains how TimSort works and provides a sample C implementation for educational purposes.
