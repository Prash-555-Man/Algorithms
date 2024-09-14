## Bingo sort
### Overview of Bingo Sort

Bingo Sort is a sorting algorithm that repeatedly identifies the smallest unsorted value (like drawing numbers in a bingo game) and places it in its correct position. This process is repeated until the entire array is sorted.

### Explanation of the C Code

1. **Include Standard Library and Define `display` Function**:
   ```c
   #include <stdio.h>
   ```

   This includes the standard input/output library, which is required for using `printf` and `scanf`.

   ```c
   // Function to display the array
   void display(int arr[], int size) {
       for (int i = 0; i < size; i++) {
           printf("%d ", arr[i]);
       }
       printf("\n");
   }
   ```
   This function prints the array to the console. It is useful for displaying the state of the array after each operation.

2. **Define `bingoSort` Function**:
   ```c
   void bingoSort(int arr[], int size) {
       // Finding the smallest and largest elements from the array
       int bingo = arr[0];
       int largest = arr[0];
       for (int i = 1; i < size; i++) {
           if (arr[i] < bingo) {
               bingo = arr[i];
           }
           if (arr[i] > largest) {
               largest = arr[i];
           }
       }
   ```

   - **Initialize `bingo` and `largest`**: 
     We start by assuming the first element is both the smallest and largest. We then iterate through the array to find the actual smallest and largest values.
   
   ```c
       int nextBingo = largest;
       int nextPos = 0;
   
       while (bingo < nextBingo) {
           // Will keep the track of the element position to be shifted to their correct position
           int startPos = nextPos;
           for (int i = startPos; i < size; i++) {
               if (arr[i] == bingo) {
                   // Swap the elements
                   int temp = arr[i];
                   arr[i] = arr[nextPos];
                   arr[nextPos] = temp;
                   nextPos++;
               } else if (arr[i] < nextBingo) {
                   nextBingo = arr[i];
               }
           }
   
           // Update bingo and nextBingo for the next pass
           bingo = nextBingo;
           nextBingo = largest;
           
           // Display the array after each pass
           printf("Array after processing %d:\n", bingo);
           display(arr, size);
       }
   
       // Final sorted array
       printf("Final sorted array:\n");
       display(arr, size);
   }
   ```

   - **Sorting Loop**: 
     The `while` loop continues until `bingo` is less than `nextBingo`. Inside the loop:
     - **Track Element Positions**: It keeps track of where `bingo` should be placed and swaps it with elements that are equal to `bingo`.
     - **Update `nextBingo`**: After placing all occurrences of the current `bingo`, find the next smallest value (`nextBingo`) that needs to be processed.
     - **Display Array**: After each pass, the `display` function is called to show the current state of the array.

3. **Define `main` Function**:
   ```c
   // Main function to test Bingo Sort
   int main() {
       int arr[] = {34, 12, 56, 12, 78, 5, 12};
       int size = sizeof(arr) / sizeof(arr[0]);
   
       printf("Original array:\n");
       display(arr, size);
   
       bingoSort(arr, size);
   
       return 0;
   }
   ```

   - **Test the Sorting Function**:
     - Define an array `arr` and calculate its size.
     - Print the original array.
     - Call the `bingoSort` function to sort the array.
     - The `display` function is used to print the array before and after sorting.

### Summary of Steps

1. **Find Minimum and Maximum**: Identify the smallest and largest values in the array.
2. **Sorting Loop**:
   - Track and place the smallest value (`bingo`) in its correct position.
   - Update to the next smallest value (`nextBingo`).
   - Repeat until all elements are placed correctly.
3. **Display State**: Print the array after each major step to visualize the sorting process.
