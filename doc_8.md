Arrays
- arr[]: Main integer array containing N random numbers
  - Dynamically allocated based on user input
  - Range: [1, 1000]

 Global Counters
-  comps : `long long` - Counts comparison operations
-  swaps : `long long` - Counts swap/shift operations
  - Reset to 0 before each sort
  - Used to analyze algorithm efficiency

Functions Implemented

1. `void printArr(int arr[], int n)`
 Purpose : Display array elements on a single line.

2. `void bubbleSort(int arr[], int n)`
 Purpose : Sort array using Bubble Sort algorithm.
Algorithm :
- Repeatedly compare adjacent elements
- Swap if they are in wrong order
- After each pass, largest element "bubbles" to end

3. `void selectionSort(int arr[], int n)`
Purpose : Sort array using Selection Sort algorithm.

Algorithm :
- Find minimum element in unsorted portion
- Swap it with first unsorted element
- Move boundary of sorted portion

4. `void insertionSort(int arr[], int n)`
Purpose : Sort array using Insertion Sort algorithm.

Algorithm :
- Build sorted array one element at a time
- Insert each element into its correct position
- Shift elements as needed

5. `void merge(int arr[], int l, int m, int r)`
Purpose : Merge two sorted subarrays into one.
Parameters :
- `l`: Left index of first subarray
- `m`: Middle index (end of first subarray)
- `r`: Right index of second subarray

6. `void mergeSortRec(int arr[], int l, int r)`
Purpose : Recursive function for Merge Sort.

Algorithm :
- Divide array into two halves
- Recursively sort each half
- Merge sorted halves

7. `void mergeSort(int arr[], int n)`
Purpose : Sort array using Merge Sort algorithm (wrapper function).


main() Method Organization

1.  Initialization :
   - Seed random number generator with current time
   - Prompt for N (size of array)
   - Validate N (1 to MAXN)

2.  Array Generation :
   - Allocate memory for array
   - Generate N random integers in range [1, 1000]
   - Display generated numbers

3.  User Choice :
   - Display menu of 4 sorting algorithms
   - Get user's choice

4.  Sorting and Statistics :
   - Execute chosen sorting algorithm
   - Display sorted array
   - Show comparisons and swaps performed

5.  Cleanup :
   - Free allocated memory

**Output**

## Selection Sort
Enter N (number of random integers, max 1000): 10

Generated numbers:
993 688 247 777 361 327 940 414 129 425

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 2

After Selection Sort:
129 247 327 361 414 425 688 777 940 993
Comparisons: 45, Swaps: 8

Enter N (number of random integers, max 1000): 10

## Merge Sort
Generated numbers:
179 756 697 130 236 774 509 400 786 433

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 4

After Merge Sort:
130 179 236 400 433 509 697 756 774 786
Comparisons: 22