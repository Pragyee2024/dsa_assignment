typedef struct Node {
    int data;
    struct Node *next;
} Node;

- `data` - Stores an integer value in the node
- `next` - Pointer that points to the next node in the list
- For the last node, `next` is `NULL` (means no more nodes)
- This creates a chain: Node1 → Node2 → Node3 → NULL


 Functions Implemented 

1. `Node* createNode(int data)`
Purpose: Creates a new node with given data
Parameters:
- `data` - Integer value to store in the new node
 Algorithm: 
-Allocate memory for new node using `malloc()`
-Check if memory allocation was successful
-Assign the data value to the node
-Set `next` pointer to `NULL`
-Return pointer to the new node
-Returns:  Pointer to newly created node

Time Complexity:  O(1)
Space Complexity:  O(1)


2. `void insertAtEnd(Node  head, int data)`
Purpose:  Adds a new node at the end of the linked list
Parameters: 
- `head` - Double pointer to the first node (to modify if list is empty)
- `data` - Integer value to store in the new node
Algorithm: 
Case 1 - Empty list (`*head == NULL`): 
- Make the new node the head of the list
- Set `*head = newNode`
Case 2 - List has nodes: 
- Initialize temporary pointer `temp` to `*head`
- Traverse to the last node: move `temp` to `next` until `temp->next == NULL`
- Link last node to new node: `temp->next = newNode`

Time Complexity:  O(n) - requires traversal to end
Space Complexity:  O(1)


3. `void displayList(Node *head)`
Purpose:  Displays all elements in the linked list in forward order
Parameters: 
- `head` - Pointer to the first node

Algorithm: 
1. Check if list is empty (`head == NULL`)
2. Initialize temporary pointer `temp` to `head`
3. Traverse the list using `next` pointers
4. Print each node's data followed by " -> "
5. Continue until `temp == NULL`
6. Print " -> NULL" at the end

Output Format:  `10 -> 20 -> 30 -> NULL`

Time Complexity:  O(n) - visits each node once


4. `void reverseTraversalRecursive(Node *head)`
Purpose:  Displays linked list in reverse order using recursion (main requirement)
Parameters: 
- `head` - Pointer to current node
Algorithm: 
Base Case: 
- If `head == NULL`, return (nothing to print)

Recursive Step: 
1. First, recursively call function for next node: `reverseTraversalRecursive(head->next)`
2. After recursion returns, print current node's data
3. Print " <- " separator

How it works: 
- Function goes to the end of the list first
- Then prints values while coming back (unwinding recursion)
- This naturally reverses the order

Call Stack:
reverseTraversal(10) calls reverseTraversal(20)
reverseTraversal(20) calls reverseTraversal(30)
reverseTraversal(30) calls reverseTraversal(NULL)
reverseTraversal(NULL) returns

Now print while returning:
reverseTraversal(30) prints "30 <- "
reverseTraversal(20) prints "20 <- "
reverseTraversal(10) prints "10 <- "


Time Complexity:  O(n) - visits each node once
Space Complexity:  O(n) - due to recursion call stack



5. `void freeList(Node  head)`
Purpose:  Frees all memory allocated for the linked list
Parameters: 
- `head` - Double pointer to the first node
Algorithm: 
1. Initialize temporary pointer `temp`
2. While `*head` is not `NULL`:
   - Save current head in `temp`
   - Move `*head` to next node
   - Free the memory of `temp`
3. All nodes are freed and list is empty

Important:  Prevents memory leaks
Time Complexity:  O(n)



**main() Method Organization**
1. Demonstration Mode (Automatic)
- Creates empty linked list with `head = NULL`
- Adds 5 elements to the list: 10, 20, 30, 40, 50
  - Uses `insertAtEnd()` for each value
- Displays the list in forward direction using `displayList()`
- Displays the list in reverse direction using `reverseTraversalRecursive()`

2. Interactive Mode (User Input)
- Creates a new empty list with `head2 = NULL`
- Prompts user: "Enter elements to add to a new list (enter -1 to stop)"
-  Loop: 
  - Asks user to enter a value
  - If value is -1, exits loop
  - Otherwise, adds value to list using `insertAtEnd()`
- If list is not empty (`head2 != NULL`):
  - Displays list in forward direction
  - Displays list in reverse direction
  - Frees the list memory
- Frees the demonstration list memory


**Output**
--- Linked List Reverse Traversal---

Creating linked list with elements: 10, 20, 30, 40, 50 

Normal Traversal (Forward):
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Reverse Traversal (Recursive Method):
NULL <- 50 <- 40 <- 30 <- 20 <- 10 <- 


--- Interactive Mode ---
Enter elements to add to a new list (enter -1 to stop):
Enter value: 28
Enter value: 74
Enter value: 11
Enter value: -1

List (Forward):
28 -> 74 -> 11 -> NULL

List (Reverse - Recursive):
NULL <- 11 <- 74 <- 28 <-