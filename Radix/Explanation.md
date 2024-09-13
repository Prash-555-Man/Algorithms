# Radix Sort
### Step-by-Step Explanation of the Code

1. **Initialization and Input**:
   - The program begins by prompting the user to enter the number of elements (`n`) in the array.
   - It then reads the `n` elements into the array `arr`.

2. **Display the Original Array**:
   - The `display` function is called to print the original array before sorting.

3. **Radix Sort Process (`radixSort` function)**:
   - The `radixSort` function starts by finding the maximum value in the array using the `getMax` function.
   - Sorting is then performed digit by digit, starting from the least significant digit (units place) and moving towards the most significant digit.
   - For each digit, the function calls `countingSortForRadix` with the current exponent (`exp`), which represents the digit position (1 for units, 10 for tens, etc.).

4. **Counting Sort for Each Digit (`countingSortForRadix` function)**:
   - **Counting Occurrences of Each Digit**:
     - The program initializes a `count` array of size 10 (since digits range from 0 to 9) to keep track of occurrences of each digit.
     - For each element in the array, it calculates which digit corresponds to the current exponent (`exp`), increments the count for that digit, and prints the updated count for each occurrence.
     - The entire count array is displayed to show the state after all counts are updated.
     
   - **Updating Count Array for Positions**:
     - The program updates the count array to reflect the actual positions of the digits by accumulating the counts.
     - For each count array element (from index 1 onwards), the value is updated by adding the value of the previous element, showing how the array is adjusted to determine where each digit should go.
     - The updated count array is displayed to show the new positions.

   - **Building the Output Array**:
     - The program uses the count array to build an output array by placing elements in their correct positions based on the current digit.
     - Starting from the last element and moving backwards, each element is placed in the output array at the position specified by the count array.
     - Each placement is printed, showing the value being placed and its position in the output array.
     - The output array is displayed after all placements.

   - **Copying Sorted Elements Back to the Original Array**:
     - The sorted elements in the output array are copied back into the original array.
     - After each copy operation, the current state of the array is displayed, showing the progressive construction of the sorted array.

5. **Repeat for Each Digit**:
   - The above process is repeated for each digit position (units, tens, hundreds, etc.) until the entire array is sorted.

6. **Display the Sorted Array**:
   - Finally, the sorted array is displayed using the `display` function.

### Example Execution
Suppose the input array is: `[170, 45, 75, 90, 802, 24, 2, 66]`. 

- **Initial Array**: `170 45 75 90 802 24 2 66`
- **Sorting by Units Digit (exp = 1)**:
  - Count digits and update positions, then arrange the elements by their units digit.
- **Sorting by Tens Digit (exp = 10)**:
  - Count digits, update positions, and arrange elements by tens.
- **Sorting by Hundreds Digit (exp = 100)**:
  - Continue similarly for hundreds, updating and placing elements accordingly.
  
**Final Sorted Array**: `2 24 45 66 75 90 170 802`
