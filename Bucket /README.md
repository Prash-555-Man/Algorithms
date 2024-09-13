# Bucket Sort in C
This program demonstrates the Bucket Sort algorithm implemented in C. Bucket Sort is a sorting algorithm that distributes elements into several buckets and then sorts each bucket individually. This implementation uses linked lists to manage buckets, allowing for efficient insertion and sorting of elements.

## How It Works

1. **Bucket Initialization**: 
   - The algorithm creates an array of empty linked lists (buckets). Each bucket corresponds to a range of values in the input array.

2. **Distribution of Elements**:
   - Each element from the input array is placed into the appropriate bucket based on its value. The element is inserted into the bucket in a sorted manner.

3. **Sorting Within Buckets**:
   - As elements are inserted into each bucket, they are kept in sorted order using a linked list insertion function.

4. **Concatenation of Buckets**:
   - The contents of all buckets are concatenated back into the original array in sorted order.

## Program Structure

### Key Functions

- **`display(float arr[], int n)`**: Displays the contents of the array.
- **`insertSorted(struct Node* list, float value)`**: Inserts a value into the bucket while maintaining sorted order.
- **`displayBucket(struct Node* list)`**: Displays the contents of a bucket.
- **`bucketSort(float arr[], int n)`**: Main sorting function that performs the bucket sort operation.

### Input and Output

- The user inputs the number of elements (`n`) and then enters `n` floating-point values.
- The program displays the original array, shows how elements are distributed into buckets, and how they are sorted within each bucket.
- Finally, the program outputs the sorted array.

## Example

### Input
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

### Output
```
Original array: 0.897 0.565 0.656 0.123 0.665 0.343 

Distributing elements into buckets:
Element 0.897 goes to bucket 5.
Inserting 0.897 at the head of the bucket.
Bucket 5: 0.897 -> NULL

Element 0.565 goes to bucket 3.
Inserting 0.565 at the head of the bucket.
Bucket 3: 0.565 -> NULL

Element 0.656 goes to bucket 3.
Inserting 0.656 into the bucket after 0.565.
Bucket 3: 0.565 -> 0.656 -> NULL

Element 0.123 goes to bucket 0.
Inserting 0.123 at the head of the bucket.
Bucket 0: 0.123 -> NULL

Element 0.665 goes to bucket 3.
Inserting 0.665 into the bucket after 0.656.
Bucket 3: 0.565 -> 0.656 -> 0.665 -> NULL

Element 0.343 goes to bucket 2.
Inserting 0.343 at the head of the bucket.
Bucket 2: 0.343 -> NULL

Concatenating all buckets back into the array:
Placing 0.123 into the array at index 0.
Placing 0.343 into the array at index 1.
Placing 0.565 into the array at index 2.
Placing 0.656 into the array at index 3.
Placing 0.665 into the array at index 4.
Placing 0.897 into the array at index 5.

Sorted array: 0.123 0.343 0.565 0.656 0.665 0.897
```

## How to Run

1. Compile the code using a C compiler (e.g., `gcc`).
   ```bash
   gcc bucket_sort.c -o bucket_sort
   ```
2. Run the compiled program.
   ```bash
   ./bucket_sort
   ```

## Features

- Displays detailed steps of the sorting process, including the distribution of elements into buckets, the insertion into sorted buckets, and the concatenation back into the array.
- Provides a clear understanding of how Bucket Sort works step-by-step.

## Applications

Bucket Sort is particularly useful when:
- Sorting data that is uniformly distributed over a range.
- The number of buckets and elements are manageable, providing an efficient sorting mechanism compared to other comparison-based sorting algorithms.

## Limitations

- Bucket Sort performs optimally when input data is uniformly distributed.
- Choosing an optimal number of buckets is crucial for performance.
- The algorithm requires additional memory for buckets.

## License

This project is open-source and available under the MIT License.
