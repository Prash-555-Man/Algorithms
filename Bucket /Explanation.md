# Bucket Sort 
### Program Explanation

1. **`struct Node` Definition**:
   - This structure defines the nodes of a linked list, used for buckets in the sorting process. Each node contains a `data` field to store a float value and a `next` pointer to link to the next node.

2. **`display()` Function**:
   - This function prints the current state of the array. It is used throughout the sorting process to show changes in the array.

3. **`insertSorted()` Function**:
   - This function inserts a given value into the correct position within a linked list (bucket) to maintain sorted order. It handles both empty lists and finding the correct position in non-empty lists.
   - `printf()` statements are used to indicate where the value is being inserted.

4. **`displayBucket()` Function**:
   - Displays the contents of a bucket (linked list) by traversing through each node.

5. **`bucketSort()` Function**:
   - This is the main sorting function. It uses buckets (linked lists) to sort the input array.

### Step-by-Step Execution

1. **Initialize Buckets**:
   - An array of pointers (`buckets`) is created, with each pointer initially set to `NULL`, indicating empty buckets.

2. **Distribute Elements into Buckets**:
   - The elements of the array are distributed into different buckets based on their values.
   - The formula `index = n * arr[i]` determines which bucket an element goes to.
   - For example, if `arr[i] = 0.565` and `n = 6`, then `index = 6 * 0.565 = 3`, placing the element in bucket 3.
   - After inserting each element, the current state of the corresponding bucket is displayed.

3. **Insert Elements into Buckets**:
   - Each element is inserted into the correct position in its respective bucket using the `insertSorted()` function.
   - If the bucket is empty or the new value is smaller than the current head, the element is inserted at the head.
   - Otherwise, the function finds the correct position for the new value, maintaining sorted order within the bucket.

4. **Concatenate Buckets Back into Array**:
   - After distributing all elements, the buckets are concatenated back into the array in sorted order.
   - The program traverses each bucket, and each element is placed back into the array in the order they appear in the bucket.
   - After placing each element, the current state of the array is displayed.

5. **Main Function Execution**:
   - The program begins by asking the user to input the number of elements (`n`) and the array elements.
   - It then calls the `bucketSort()` function, which performs the sorting.
   - Finally, the sorted array is displayed.

### Example Run with Detailed Steps

If the input is:

```
Enter the value of n: 6
Enter n elements:
0.897
0.565
0.656
0.123
0.665
0.343
```

The output will detail each operation as follows:

1. **Original array**:
   ```
   0.897 0.565 0.656 0.123 0.665 0.343
   ```

2. **Distributing Elements into Buckets**:
   - Element `0.897` goes to bucket `5`.
     ```
     Inserting 0.897 at the head of the bucket.
     Bucket 5: 0.897 -> NULL
     ```
   - Element `0.565` goes to bucket `3`.
     ```
     Inserting 0.565 at the head of the bucket.
     Bucket 3: 0.565 -> NULL
     ```
   - Element `0.656` goes to bucket `3`.
     ```
     Inserting 0.656 into the bucket after 0.565.
     Bucket 3: 0.565 -> 0.656 -> NULL
     ```
   - Element `0.123` goes to bucket `0`.
     ```
     Inserting 0.123 at the head of the bucket.
     Bucket 0: 0.123 -> NULL
     ```
   - Element `0.665` goes to bucket `3`.
     ```
     Inserting 0.665 into the bucket after 0.656.
     Bucket 3: 0.565 -> 0.656 -> 0.665 -> NULL
     ```
   - Element `0.343` goes to bucket `2`.
     ```
     Inserting 0.343 at the head of the bucket.
     Bucket 2: 0.343 -> NULL
     ```

3. **Concatenating Buckets Back into the Array**:
   - Concatenating Bucket `0`:
     ```
     Placing 0.123 into the array at index 0.
     Current array: 0.123 0.565 0.656 0.123 0.665 0.343
     ```
   - Concatenating Bucket `2`:
     ```
     Placing 0.343 into the array at index 1.
     Current array: 0.123 0.343 0.656 0.123 0.665 0.343
     ```
   - Concatenating Bucket `3`:
     ```
     Placing 0.565 into the array at index 2.
     Current array: 0.123 0.343 0.565 0.123 0.665 0.343
     Placing 0.656 into the array at index 3.
     Current array: 0.123 0.343 0.565 0.656 0.665 0.343
     Placing 0.665 into the array at index 4.
     Current array: 0.123 0.343 0.565 0.656 0.665 0.343
     ```
   - Concatenating Bucket `5`:
     ```
     Placing 0.897 into the array at index 5.
     Current array: 0.123 0.343 0.565 0.656 0.665 0.897
     ```

4. **Sorted Array**:
   ```
   0.123 0.343 0.565 0.656 0.665 0.897
   ```

This detailed approach helps track the sorting process step-by-step, providing a clear view of how Bucket Sort organizes the data.
