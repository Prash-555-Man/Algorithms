### Shell Sort Explanation:

**Shell Sort** is a generalization of Insertion Sort that allows the exchange of items that are far apart. It works by first sorting elements far apart from each other and progressively reducing the gap between elements to be compared.

#### Key Concepts:
1. **Gap Sequence**: 
   - Shell Sort uses a gap sequence to compare and sort elements. Initially, the gap is set to `n/2` (where `n` is the number of elements in the array), and it reduces by half on each iteration (`gap = gap / 2`) until the gap becomes 1.
   - A gap of 1 essentially converts Shell Sort into Insertion Sort.

2. **Sorting with Gaps**: 
   - For each gap, Shell Sort performs a **gapped insertion sort**, meaning it compares and sorts elements that are `gap` indices apart. This way, larger gaps allow for moving elements long distances, helping the array get closer to being sorted.

3. **Insertion Sort**: 
   - The insertion sort performed for each gap compares elements that are separated by the current gap and shifts them to their correct positions relative to the gap.

---

### Step-by-Step Explanation of Code:

#### 1. **`display(int arr[], int n)`**:
   - This helper function prints the current state of the array at various stages of the algorithm. It is used to display the original array, intermediate stages of sorting, and the final sorted array.

   ```c
   void display(int arr[], int n) {
       for (int i = 0; i < n; i++) {
           printf("%d ", arr[i]);
       }
       printf("\n");
   }
   ```

#### 2. **`shellSort(int arr[], int n)`**:
   - **Initialization**:
     - The function starts by defining a `gap` value, initially set to half of the array size (`n/2`). The gap is reduced by half on each iteration (`gap /= 2`) until it becomes 1.
     
   - **Gap-Based Sorting**:
     - For each gap, the algorithm performs a gapped insertion sort, meaning that it compares elements that are separated by the current gap.
     - The element at `arr[i]` is temporarily stored in `temp`, and the previous elements (from `i - gap` downwards) are compared. If an element is larger than `temp`, it is shifted to the right to make space for `temp`.

   - **Inner Loop**:
     - This loop is responsible for shifting elements and inserting `temp` into the correct position relative to the current gap.
     
   - **Print Statements**:
     - After every insertion, the state of the array is printed using the `display()` function to show how the array evolves at each step.

   ```c
   void shellSort(int arr[], int n) {
       // Start with a large gap, then reduce the gap
       for (int gap = n / 2; gap > 0; gap /= 2) {
           printf("\nSorting with gap = %d\n", gap);

           // Perform gapped insertion sort for this gap size
           for (int i = gap; i < n; i++) {
               int temp = arr[i];
               int j;

               // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
               for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                   arr[j] = arr[j - gap];
               }

               // Put temp (the original arr[i]) in its correct location
               arr[j] = temp;

               // Display the array after each gap insertion
               printf("Array after inserting element at index %d:\n", i);
               display(arr, n);
           }
       }
   }
   ```

#### 3. **Main Function**:
   - This function handles user input, calls the `shellSort()` function, and displays the array at different stages.
   - It first accepts the number of elements (`n`) and the array elements from the user. After sorting, it prints the original and final sorted arrays using `display()`.

   ```c
   int main() {
       int n, i;

       // Input the number of elements
       printf("Enter the number of elements: ");
       scanf("%d", &n);
       
       int arr[n];

       // Input array elements
       printf("Enter the elements of the array:\n");
       for (i = 0; i < n; i++) {
           scanf("%d", &arr[i]);
       }

       // Display the original array
       printf("\nOriginal array:\n");
       display(arr, n);

       // Perform Shell Sort
       shellSort(arr, n);

       // Display the final sorted array
       printf("\nFinal sorted array:\n");
       display(arr, n);

       return 0;
   }
   ```

---

### Example Execution:

Let's assume the input array is:
```
12 34 54 2 3 89 11
```

The **Shell Sort** process will look like this:

1. **Original Array**:
   ```
   12 34 54 2 3 89 11
   ```

2. **Gap = 3**:
   - The elements at indices `0`, `3`, `6` are compared and sorted.
   
   After comparing and sorting the elements at the specified gaps:
   ```
   2 34 54 12 3 89 11
   2 3 54 12 34 89 11
   2 3 11 12 34 89 54
   ```

3. **Gap = 1**:
   - The array is now sorted using a regular Insertion Sort (gap of 1).
   
   The final result:
   ```
   2 3 11 12 34 54 89
   ```

---

### Conclusion:
Shell Sort is an efficient algorithm, especially when the array is nearly sorted. It works by reducing the gap between compared elements progressively, making fewer shifts than Insertion Sort. The `printf()` and `display()` functions in this implementation help visualize each stage of the sorting process, making it easy to understand how the algorithm works step by step.
