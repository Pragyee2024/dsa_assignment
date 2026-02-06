struct node {
    struct node* prev;
    int data;
    struct node* next;
}; 
The structure has two pointers struct node* prev points to previous node and struct node* next points to next node
prev pointer is NULL for head 
next pointer is NULL for tail
Functions Implemented
1. struct node* addToEmpty(struct node* head, int data)
Purpose: Creates the first node in an empty doubly linked list
Parameters:
head: Current head pointer (initially NULL)
data: Integer value to store in the new node
Algorithm:
Allocate memory for new node using malloc()
Assign the data value to new node
Set both prev and next pointers to NULL 
Return pointer to new node as the new head

Returns: Pointer to the newly created node (becomes new head)
Time Complexity: O(1)
Space Complexity: O(1)

2. struct node* addAtEnd(struct node* head, int data)
Purpose: Adds a new node at the end of the doubly linked list
Parameters:
head: Pointer to the first node of the list
data: Integer value to store in the new node
Algorithm:
Create new node with data and set prev and next to NULL
Initialize temporary pointer tp to head
Traverse the list: move tp to next until tp->next == NULL
Link last node to new node: tp->next = newNode
Set new node's previous pointer: newNode->prev = tp

Returns: Original head pointer (unchanged)
Time Complexity: O(n) - requires traversal to end
Space Complexity: O(1)

3. struct node* addAfterPosition(struct node* head, int data, int pos)
Purpose: Inserts a new node after a specified position in the list (main requirement)
Parameters:
head: Pointer to the first node
data: Integer value for the new node
pos: Position after which to insert 
Algorithm:
Create new node using addToEmpty() helper function
Initialize temp pointer to head
Traverse to position: decrement pos and move temp to next node

Case 1 - Inserting at end (temp->next == NULL):
Set temp->next to new node
Set newNode->prev to temp

Case 2 - Inserting in middle:
Save reference to next node: temp2 = temp->next
Link current node to new node: temp->next = newNode
Set new node's prev: newNode->prev = temp
Link new node to next node: newNode->next = temp2
Update next node's prev: temp2->prev = newNode

Returns: Head pointer (unchanged)
Time Complexity: O(n) - traversal to position

4. struct node* delInter(struct node* head, int pos)
Purpose: Deletes a node at a specific position from the doubly linked list 
Parameters:
head: Pointer to the first node
pos: Position of node to delete 
Algorithm:
Initialize temp to head and temp2 to NULL

Update head to next node: head = temp->next
If new head exists, set its prev to NULL
Free old head node
Return new head

Deleting end node:
Traverse to position: decrement pos and move temp forward
Validate position exists (check if temp == NULL)
Save previous node: temp2 = temp->prev
Link previous node to next node: temp2->next = temp->next
If next node exists, update its prev: temp->next->prev = temp2
Free the deleted node

Returns: Updated head pointer (may change if first node deleted)
Time Complexity: O(n) - traversal to position
Error Handling: Checks for out-of-bounds position


5. void display(struct node* head)
Purpose: Displays all elements in the doubly linked list in forward order
Parameters: head - Pointer to the first node
Algorithm:

Initialize temporary pointer temp to head
Traverse the list using next pointers
Print each node's data followed by a space
Continue until temp == NULL
Print newline at the end

Time Complexity: O(n) - visits each node once

main() method organization
-Node is added to empty doubly linked list (addToEmpty())
-Node is added at end (addToEnd())
-Insertion of node after position (position=2) 
-Display Doubly linked list after insertion
-Delete node at position = 3
-Display Doubly linked list after deletion

**Output**
List after adding elements: 10 20 25 30
List after deleting element at position 3: 10 20 30