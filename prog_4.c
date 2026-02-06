#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;      //Pointer to the previous node
    int data;
    struct node* next;      //Pointer to the next node
};

// Function to create a new node and add it to an empty list
struct node* addToEmpty(struct node* head, int data) {  
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    head = temp;
    return head;
}

// Function to add a node at the end of the list
struct node* addAtEnd(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    struct node*tp;
    tp=head;
    while (tp->next != NULL) {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;

    return head;
}

// Function to add a node after a specific position
struct node* addAfterPosition(struct node* head, int data, int pos) {
    struct node* newP=NULL;         //New node pointer
    struct node* temp=head;         //Temporary pointer to traverse the list
    struct node* temp2=NULL;        //Second temporary pointer
    newP=addToEmpty(newP, data);       //New node creation

    while(pos!=1)               //Traverse to the position
    {
        temp=temp->next;        //Move to next node
        pos--;
    }
    
    if(temp->next==NULL)        //If at the end of the list
    {
        temp->next=newP;        //Link new node at the end
        newP->prev=temp;        
    }
    else            //If in between nodes
    {
        temp2=temp->next;       
        temp->next=newP;
        newP->prev=temp;
        newP->next=temp2;
        temp2->prev=newP;
    }
    return head;
}

// Function to delete a node at a specific position
struct node* delInter(struct node* head, int pos) {    
    struct node* temp = head;
    struct node* temp2 = NULL;

    if (pos == 1) {               // Deleting the head node
        head = temp->next;          // Move head to next node
        if (head != NULL) {         // If list is not empty after deletion
            head->prev = NULL;      // Update previous pointer of new head
        }
        free(temp);
        return head;
    }

    while (pos != 1 && temp != NULL) {      // Traverse to the position
        temp = temp->next;          
        pos--;
    }

    if (temp == NULL) {                 // If position is out of bounds
        printf("Position out of bounds\n");
        return head;
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    if (temp->next != NULL) {           // If not deleting the last node
        temp->next->prev = temp2;       // Update previous pointer of next node
    }

    free(temp);
    return head;
}

// Function to display the list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    head = addToEmpty(head, 10);
    head = addAtEnd(head, 20);
    head = addAtEnd(head, 30);
    head = addAfterPosition(head, 25, 2);
    printf("List after adding elements: ");
    display(head);

    head = delInter(head, 3);
    printf("List after deleting element at position 3: ");
    display(head);

    return 0;
}