# Comb Sort Algorithm Explained

## Introduction

Comb Sort is a relatively simple sorting algorithm designed to improve on the inefficiencies of Bubble Sort. The main idea behind Comb Sort is to eliminate small values, or "turtles," near the end of the list that cause Bubble Sort to perform many unnecessary comparisons. By introducing a gap between elements that are compared, Comb Sort reduces the number of comparisons, especially in the early stages of sorting.

This document explains each part of the **Comb Sort** implementation in C, walking through the logic, the role of each function, and how the code behaves step-by-step.


## Breakdown of the Code

### 1. **display() Function**

```c
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```

- **Purpose**: This function prints the array at various stages of the sorting process.
- **How it Works**: It loops through the array and prints each element, followed by a space. The array is displayed after significant steps, like after each pass with a new gap, to give insight into the sorting process.

### 2. **getNextGap() Function**

```c
int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1) return 1;
    return gap;
}
```

- **Purpose**: This function calculates the next gap size to be used in the sort. Initially, the gap is the size of the array, and it shrinks by a factor of roughly 1.3 each time until it reaches 1.
- **How it Works**: The gap is divided by 1.3 using integer arithmetic. If the result is less than 1, it returns 1 to ensure that the final pass behaves like Bubble Sort (where adjacent elements are compared).

### 3. **combSort() Function**

```c
void combSort(int arr[], int n) {
    int gap = n;
    int swapped = 1;

    while (gap != 1 || swapped == 1) {
        gap = getNextGap(gap);
        swapped = 0;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }

        printf("Array after gap %d pass:\n", gap);
        display(arr, n);
    }
}
```

- **Purpose**: This is the main function that implements the Comb Sort algorithm. It controls the sorting process by repeatedly adjusting the gap and performing element comparisons and swaps.

#### Step-by-Step Explanation:

1. **Initialize Variables**:
   - `gap`: Set to the size of the array initially.
   - `swapped`: A flag to track whether any elements were swapped during a pass. This ensures that the algorithm keeps running even when the gap becomes 1 (Bubble Sort phase), but stops when no swaps are needed.

2. **Main Loop**:
   - The loop continues as long as either the gap is greater than 1 or a swap was made in the previous pass. This ensures that the array is fully sorted even after the gap reduces to 1.

3. **Adjust the Gap**:
   - The `gap` is recalculated using `getNextGap()`. Initially, the gap is large, allowing far-apart elements to be compared. As sorting progresses, the gap shrinks.

4. **Element Comparison and Swapping**:
   - For each gap, elements that are `gap` positions apart are compared. If the first element is greater than the second, they are swapped. This process moves smaller elements towards the front of the array and larger ones towards the back.

5. **Check for Swaps**:
   - If a swap occurs, `swapped` is set to 1, indicating that the algorithm should continue. If no swaps are made during a pass, the array is considered sorted when the gap becomes 1.

6. **Display the Array**:
   - After each pass with a new gap, the current state of the array is printed using the `display()` function. This helps visualize how the array evolves with each pass.

### 4. **Main Function**

```c
int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    display(arr, n);

    combSort(arr, n);

    printf("\nSorted array:\n");
    display(arr, n);

    return 0;
}
```

- **Purpose**: This is the driver function that prompts the user to enter the array, calls the sorting function, and prints the results.

#### Step-by-Step Explanation:

1. **Input the Array**:
   - The user is prompted to enter the number of elements (`n`) and the elements themselves. These are stored in the array `arr[]`.

2. **Display the Original Array**:
   - Before sorting begins, the original array is printed to show the starting point.

3. **Call `combSort()`**:
   - The `combSort()` function is invoked to sort the array.

4. **Display the Sorted Array**:
   - After sorting, the sorted array is displayed to confirm that the algorithm has worked correctly.


## Example Walkthrough

Let’s consider an example where the input array is:

```
[10, 9, 3, 7, 6, 5, 4, 2, 1, 8]
```

1. **Initial Gap Calculation**:
   - The initial gap is 10 (size of the array).
   - After dividing by 1.3, the gap becomes 7.

2. **First Pass (Gap = 7)**:
   - Elements 0 and 7, 1 and 8, 2 and 9 are compared and swapped if necessary.
   - After this pass, the array might look something like:
   
     ```
     [2, 1, 3, 7, 6, 5, 4, 10, 9, 8]
     ```

3. **Next Pass (Gap = 5)**:
   - Elements 0 and 5, 1 and 6, etc., are compared and swapped.
   - The process continues until the gap is reduced to 1.

4. **Final Pass (Gap = 1)**:
   - The algorithm behaves like Bubble Sort now, making adjacent comparisons and swaps if needed.

5. **Sorted Array**:
   - After all passes, the array will be fully sorted.


## Time Complexity

- **Best Case**: \(O(n \log n)\)
- **Average Case**: \(O(n \log n)\)
- **Worst Case**: \(O(n^2)\)

The average case for Comb Sort is faster than Bubble Sort due to the larger initial gap, which allows for faster movement of elements early on.


## Conclusion

Comb Sort is a relatively simple yet efficient algorithm for small-to-medium-sized datasets. It improves on Bubble Sort by reducing the number of comparisons and swaps through the use of a gap, which shrinks as the algorithm progresses. The implementation provided here is straightforward, and the `display()` function allows for easy tracking of the algorithm’s progress.
