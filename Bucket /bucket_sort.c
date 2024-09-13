#include <stdio.h>
#include <stdlib.h>

// Node structure for a bucket
struct Node {
    float data;
    struct Node* next;
};

// Function to display the array
void display(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n\n");
}

// Function to insert an element into the sorted bucket
struct Node* insertSorted(struct Node* list, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the bucket is empty or the value is smaller than the head
    if (list == NULL || list->data > value) {
        newNode->next = list;
        printf("Inserting %.3f at the head of the bucket.\n", value);
        return newNode;
    }

    // Find the correct position to insert
    struct Node* current = list;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("Inserting %.3f into the bucket after %.3f.\n", value, current->data);

    return list;
}

// Function to display the contents of a bucket
void displayBucket(struct Node* list) {
    while (list != NULL) {
        printf("%.3f -> ", list->data);
        list = list->next;
    }
    printf("NULL\n\n");
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    struct Node* buckets[n]; // Array of bucket heads

    // Initialize all buckets as empty
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Distribute array elements into buckets
    printf("\nDistributing elements into buckets:\n");
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // Index calculation
        printf("Element %.3f goes to bucket %d.\n", arr[i], index);
        buckets[index] = insertSorted(buckets[index], arr[i]);
        printf("Bucket %d after inserting %.3f: ", index, arr[i]);
        displayBucket(buckets[index]);
    }

    // Concatenate all buckets back into the array
    printf("\nConcatenating all buckets back into the array:\n");
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        printf("Bucket %d contents: ", i);
        displayBucket(current);
        while (current != NULL) {
            printf("Placing %.3f into the array at index %d.\n", current->data, index);
            arr[index++] = current->data;
            display(arr, n);  // Display the array after each placement
            current = current->next;
        }
    }
}

// Main function to demonstrate Bucket Sort
int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter n elements:\n");
    for (i=0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    printf("\n\nOriginal array: ");
    display(arr, n);

    bucketSort(arr, n);

    printf("\nSorted array: ");
    display(arr, n);

    return 0;
}
