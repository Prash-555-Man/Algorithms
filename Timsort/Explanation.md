# Tim Sort 

### Step-by-Step Explanation

1. **Display Function (`display()`)**:
   This function prints the array in its current state after every operation, helping to visually understand the steps.

2. **Insertion Sort (`insertionSort()`)**:
   - This sorts small subarrays (called **runs**) using the Insertion Sort algorithm.
   - The range from `left` to `right` (which is no larger than `RUN = 32`) is sorted by repeatedly moving elements to their correct positions.
   - After sorting each subarray, the function prints the state of the array.

3. **Merge Function (`merge()`)**:
   - This function merges two sorted subarrays: `left[]` and `right[]` (generated by the Insertion Sort).
   - The merged array is displayed after each merge operation, showing how the sorted sections combine.

4. **TimSort (`timSort()`)**:
   - It begins by applying **Insertion Sort** on small sections of the array (called **runs**).
   - After sorting the small sections, it merges the sorted runs using **Merge Sort** until the entire array is sorted.
   - For each merging step, the current state of the array is printed for clarity.

5. **Main Function**:
   - It initializes an array, prints its initial state, and then calls the `timSort()` function to sort the array step by step.
   - After sorting, the final state of the array is printed.

### Example Output

```
Original array: 5 21 7 23 19 10 14 3 27 8 16 

Performing Insertion Sort from index 0 to 10
Array after inserting element at index 1: 5 21 7 23 19 10 14 3 27 8 16 
Array after inserting element at index 2: 5 7 21 23 19 10 14 3 27 8 16 
...
Array after inserting element at index 10: 3 5 7 8 10 14 16 19 21 23 27 

Final sorted array: 3 5 7 8 10 14 16 19 21 23 27
```

The output shows the array being sorted incrementally and merges being applied.
