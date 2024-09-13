# Counting Sort
### **Step-by-Step Explanation**

1. **Input Array and Initialization**:
   - The program starts by prompting the user to input the size of the array `n` and the elements of the array.
   - For example, if the input is:
     ```
     Enter the value of n: 5
     Enter n elements:
     4 2 2 8 3
     ```
   - The original array is then displayed as:
     ```
     Original array: 4 2 2 8 3
     ```

2. **Finding the Maximum Value (`findMax` function)**:
   - The `findMax` function scans the array to find the maximum value, which is used to determine the size of the `count` array.
   - In this example, the maximum value is `8`.

3. **Initialization of the Count Array**:
   - A `count` array of size `max + 1` (here `9`) is initialized with zeros.
   - This array will be used to count occurrences of each element in the input array.

4. **Counting Occurrences**:
   - The program iterates over the input array, and for each element `arr[i]`, it increments `count[arr[i]]` by `1`.
   - The updated count array is displayed after each increment.

   **Example**:
   - For the input array `[4, 2, 2, 8, 3]`:
     ```
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
     ```

5. **Updating the Count Array for Positions**:
   - The program updates the count array to accumulate counts, which represent positions in the output array.
   - This helps determine where each element should go in the sorted array.

   **Example**:
   ```
   Updating count[1] to 0
   Updating count[2] to 2
   Updating count[3] to 3
   Updating count[4] to 4
   Updating count[5] to 4
   Updating count[6] to 4
   Updating count[7] to 4
   Updating count[8] to 5
   ```

6. **Building the Output Array**:
   - The program builds the sorted array by placing each element from the original array into its correct position based on the count array.
   - It traverses the original array from the end to maintain stability (elements with the same value appear in the same order as in the input).

   **Example**:
   - For each element, the corresponding count is decremented after placing the element:
     ```
     Placing 3 at position 2
     Placing 8 at position 4
     Placing 2 at position 1
     Placing 2 at position 0
     ```

7. **Copying the Sorted Array to the Original Array**:
   - Finally, the sorted elements from the output array are copied back to the original array.

   **Example**:
   ```
   Copying 2 to arr[0]
   Copying 2 to arr[1]
   Copying 3 to arr[2]
   Copying 4 to arr[3]
   Copying 8 to arr[4]
   ```

### **Summary of Output**
After completing all the steps, the program displays the sorted array:
```
Sorted array: 2 2 3 4 8
```

### **Key Points**
- The program uses a count array to count occurrences of each value.
- The count array is modified to represent positions for sorting.
- Elements are placed in the output array based on these positions, and then copied back to the original array.
