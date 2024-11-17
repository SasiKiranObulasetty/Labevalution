#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(int arr[], int n, int i) {
    int smallest = i;  
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void add(int arr[], int *size, int key) {
    arr[*size] = key;
    (*size)++;
}
int findKthLargest(int arr[], int size, int k) {
    heapSort(arr, size);
    return arr[k-1];
}
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[100] = {3, 2, 8, 1};  
    int n = 4;  
    int choice, score, k;
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add a score\n");
        printf("2. Find k-th largest score\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter score to add: ");
            scanf("%d", &score);
            add(arr, &n, score);
            heapSort(arr, n); 
            printArray(arr, n);
        } else if (choice == 2) {
            printf("Enter value of k (to find k-th largest score): ");
            scanf("%d", &k);
            if (k > 0 && k <= n) {
                int kthLargest = findKthLargest(arr, n, k);
                printf("The %d-th largest score is: %d\n", k, kthLargest);
            } else {
                printf("Invalid value for k. Must be between 1 and %d.\n", n);
            }
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;

        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
