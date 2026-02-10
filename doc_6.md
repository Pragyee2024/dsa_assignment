int arr[]  // Array to store heap elements
int n      // Number of elements in heap

- Heaps are stored as arrays (no structure needed)
- Uses complete binary tree property
- Parent-child relationships calculated using indices

Heap Properties:
- **Max Heap**: Parent ≥ Both children, largest at root
- **Min Heap**: Parent ≤ Both children, smallest at root

Index Formulas:
- Parent of index i: `(i - 1) / 2`
- Left child of i: `2 * i + 1`
- Right child of i: `2 * i + 2`

Functions Implemented

1. `void swap(int *a, int *b)`

Purpose: Swaps two integer values
Parameters:
- `a` - Pointer to first integer
- `b` - Pointer to second integer

Algorithm:
- Store value at `a` in temporary variable
- Copy value from `b` to `a`
- Copy temporary to `b`

2. `void maxHeapify(int arr[], int n, int i)`

Purpose: Maintains max-heap property at node i
Parameters:
- `arr[]` - Array representing heap
- `n` - Size of heap
- `i` - Index of node to heapify

Algorithm:
- Set `largest = i`
- Calculate left child: `l = 2*i + 1`
- Calculate right child: `r = 2*i + 2`
- If left child exists and `arr[l] > arr[largest]`, update `largest = l`
- If right child exists and `arr[r] > arr[largest]`, update `largest = r`
- If `largest != i`:
  - Swap `arr[i]` with `arr[largest]`
  - Recursively call `maxHeapify(arr, n, largest)`


3. `void buildMaxHeap(int arr[], int n)`

Purpose: Converts unsorted array into max-heap (main requirement)
Parameters:
- `arr[]` - Array to convert
- `n` - Number of elements
Algorithm:
- Find last non-leaf node: `n/2 - 1`
- Loop from `i = n/2 - 1` down to 0
- Call `maxHeapify(arr, n, i)` for each node
- Bottom-up approach ensures all subtrees are valid heaps

4. `void minHeapify(int arr[], int n, int i)`

Purpose: Maintains min-heap property at node i
Parameters:
- `arr[]` - Array representing heap
- `n` - Size of heap
- `i` - Index of node to heapify
Algorithm:
- Set `smallest = i`
- Calculate left child: `l = 2*i + 1`
- Calculate right child: `r = 2*i + 2`
- If left child exists and `arr[l] < arr[smallest]`, update `smallest = l`
- If right child exists and `arr[r] < arr[smallest]`, update `smallest = r`
- If `smallest != i`:
  - Swap `arr[i]` with `arr[smallest]`
  - Recursively call `minHeapify(arr, n, smallest)`


5. `void buildMinHeap(int arr[], int n)`

Purpose: Converts unsorted array into min-heap (main requirement)
Parameters:
- `arr[]` - Array to convert
- `n` - Number of elements
Algorithm:
- Find last non-leaf node: `n/2 - 1`
- Loop from `i = n/2 - 1` down to 0
- Call `minHeapify(arr, n, i)` for each node
- Bottom-up approach ensures correctness

6. `void printArr(int arr[], int n)`

Purpose: Prints array elements
Parameters:
- `arr[]` - Array to print
- `n` - Number of elements

Algorithm:
- Loop from 0 to n-1
- Print each element with space
- Print newline at end

main() Method Organization

1. Input 
- User inputs number of elements n
- Validate input
- Allocate memory for original array
- Read n elements from user

2. Array Duplication
- Allocate memory for `arrMax` (max-heap copy)
- Allocate memory for `arrMin` (min-heap copy)
- Copy all elements to both arrays

3. Heap Construction
- Call `buildMaxHeap(arrMax, n)` to create max-heap
- Call `buildMinHeap(arrMin, n)` to create min-heap

4. Display Results
- Print original unsorted array
- Print max-heap array representation
- Print min-heap array representation

5. Cleanup
- Free all dynamically allocated arrays

**Output**
Enter number of elements: 4
Enter 4 elements (unsorted):
7
8
6
9
Original array:
7 8 6 9 
Max-heap array representation:
9 8 6 7 
Min-heap array representation:
6 8 7 9 