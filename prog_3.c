#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display linked list (forward)
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

//Recursive reverse traversal
void reverseTraversalRecursive(Node *head) {
    if (head == NULL) {
        return;
    }
    
    //traverse to the end
    reverseTraversalRecursive(head->next);
    
    // Then print 
    printf("%d", head->data);
    if (head != NULL) {
        printf(" <- ");
    }
}

// Function to free the linked list
void freeList(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    
    printf("--- Linked List Reverse Traversal---\n\n");
    
    // Create a sample linked list
    printf("Creating linked list with elements: 10, 20, 30, 40, 50\n\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Display normal traversal
    printf("Normal Traversal (Forward):\n");
    displayList(head);
    printf("\n");
    
    printf("Reverse Traversal (Recursive Method):\n");
    printf("NULL <- ");
    reverseTraversalRecursive(head);
    printf("\n\n");
    
    // Interactive section
    printf("\n--- Interactive Mode ---\n");
    printf("Enter elements to add to a new list (enter -1 to stop):\n");
    
    Node *head2 = NULL;
    int value;
    
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        
        if (value == -1) {
            break;
        }
        
        insertAtEnd(&head2, value);
    }
    
    if (head2 != NULL) {
        printf("\nList (Forward):\n");
        displayList(head2);
        
        printf("\nList (Reverse - Recursive):\n");
        printf("NULL <- ");
        reverseTraversalRecursive(head2);
        printf("\n");
        
        freeList(&head2);
    }
    
    // Free memory
    freeList(&head);
    
    return 0;
}