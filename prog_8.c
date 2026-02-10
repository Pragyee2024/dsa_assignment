#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000

// Global counters for comparisons and swaps
long long comps = 0;
long long swaps = 0;

// Function to print an array
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) 
        printf("%d ", arr[i]);
    printf("\n");
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    comps = swaps = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            comps++;
            if (arr[j] > arr[j+1]) {
                int t = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = t;
                swaps++;
            }
        }
    }
}

// Selection Sort Algorithm
void selectionSort(int arr[], int n) {
    comps = swaps = 0;
    for (int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for (int j = i+1; j < n; ++j) {
            comps++;
            if (arr[j] < arr[minIdx]) 
                minIdx = j;
        }
        if (minIdx != i) {
            int t = arr[i]; 
            arr[i] = arr[minIdx]; 
            arr[minIdx] = t;
            swaps++;
        }
    }
}

// Insertion Sort Algorithm
void insertionSort(int arr[], int n) {
    comps = swaps = 0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            comps++;
            arr[j+1] = arr[j];
            swaps++;
            j--;
        }
        // Count the final comparison that breaks the loop
        if (j >= 0) comps++;
        
        arr[j+1] = key;
    }
}

// Merge function for merge sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; ++i) 
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) 
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comps++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) 
        arr[k++] = L[i++];
    while (j < n2) 
        arr[k++] = R[j++];
    
    free(L); 
    free(R);
}

// Recursive merge sort function
void mergeSortRec(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSortRec(arr, l, m);
        mergeSortRec(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Merge Sort Algorithm
void mergeSort(int arr[], int n) {
    comps = swaps = 0;
    mergeSortRec(arr, 0, n-1);
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    
    printf("Enter N (number of random integers, max %d): ", MAXN);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAXN) {
        printf("Invalid N\n"); 
        return 1;
    }
    
    int *arr = malloc(sizeof(int)*n);
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Generate random numbers
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000 + 1; // [1,1000]
    }
    
    printf("\nGenerated numbers:\n");
    printArr(arr, n);
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    
    int choice;
    if (scanf("%d", &choice) != 1) {
        free(arr);
        return 1;
    }
    
    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("\nAfter Bubble Sort:\n");
            printArr(arr, n);
            printf("Comparisons: %lld, Swaps: %lld\n", comps, swaps);
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nAfter Selection Sort:\n");
            printArr(arr, n);
            printf("Comparisons: %lld, Swaps: %lld\n", comps, swaps);
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nAfter Insertion Sort:\n");
            printArr(arr, n);
            printf("Comparisons: %lld, Swaps (shifts): %lld\n", comps, swaps);
            break;
        case 4:
            mergeSort(arr, n);
            printf("\nAfter Merge Sort:\n");
            printArr(arr, n);
            printf("Comparisons: %lld\n", comps);
            
            break;
        default:
            printf("Invalid choice\n");
    }
    
    free(arr);
    return 0;
}