The stack is defined using a typedef structure and is given a name Stack.
The MAX SIZE is defined to be 100
The operations in stack : push, pop, peek are used for the operations to be done in prog1.c
Functions Implemented:
1. void initStack(Stack *s)
Purpose: Initializes the stack by setting top to -1
Parameters: Pointer to Stack structure

2. bool isEmpty(Stack *s)
Purpose: Checks if the stack is empty
Returns: true if top == -1, false otherwise

3. bool isFull(Stack *s)
Purpose: Checks if the stack is full
Returns: true if top == MAX_SIZE - 1, false otherwise

4. void push(Stack *s, char ch)
Purpose: Pushes a character onto the stack
Parameters: Stack pointer and character to push
Action: Increments top and stores character

5. char pop(Stack *s)
Purpose: Removes and returns the top element
Returns: Character at top of stack, '\0' if empty

6. char peek(Stack *s)
Purpose: Returns top element without removing it
Returns: Character at top, '\0' if empty

7. bool isOpeningBracket(char ch)
Purpose: Checks if character is '(', '[', or '{'
Returns: true if opening bracket, false otherwise

8. bool isClosingBracket(char ch)
Purpose: Checks if character is ')', ']', or '}'
Returns: true if closing bracket, false otherwise

9. bool isMatchingPair(char opening, char closing)
Purpose: Verifies if opening and closing brackets match
Returns: true if brackets form a valid pair

10. bool isBalanced(char *expression)
Purpose: Main algorithm to check if expression has balanced parentheses
Algorithm:
Traverse the expression character by character
If opening bracket found, push onto stack
If closing bracket found:
    -Check if stack is empty (unbalanced)
    -Pop from stack and verify it matches

After traversal, check if stack is empty (balanced)

Returns: true if balanced, false otherwise

main() method organization
-The three expressions are tested as per question
-for loop is used to iterate and check each expression
-after checking the expressions balances parantheses is checked

Output:
Balanced Parentheses Checker 

Expression 1: a + (b - c) * (d
Result: Not Balanced

Expression 2: m + [a - b * (c + d * {m)]
Result: Not Balanced

Expression 3: a + (b - c)
Result: Balanced