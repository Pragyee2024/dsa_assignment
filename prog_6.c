#include <stdio.h>
#include <stdlib.h>

// Helper swap
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// heapify for max-heap (root i, heap size n)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// build max heap
void buildMaxHeap(int arr[], int n) {
    // last non-leaf = n/2 - 1
    for (int i = n/2 - 1; i >= 0; --i)
        maxHeapify(arr, n, i);
}

// heapify for min-heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// build min heap
void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i)
        minHeapify(arr, n, i);
}

// print
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *arr = malloc(sizeof(int)*n);
    printf("Enter %d elements (unsorted):\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    int *arrMax = malloc(sizeof(int)*n);
    int *arrMin = malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i) {
        arrMax[i] = arr[i];
        arrMin[i] = arr[i];
    }

    buildMaxHeap(arrMax, n);
    buildMinHeap(arrMin, n);

    printf("Original array:\n"); printArr(arr, n);
    printf("Max-heap array representation:\n"); printArr(arrMax, n);
    printf("Min-heap array representation:\n"); printArr(arrMin, n);

    free(arr); free(arrMax); free(arrMin);
    return 0;
}
