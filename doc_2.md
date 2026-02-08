MAX_SIZE=100
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;
-Used to store operators during conversion

typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;
-Used to store operands during evaluation

Functions Implemented
For Characters:
1. void initCharStack(CharStack *s)
Initializes character stack by setting top to -1

2. bool isCharStackEmpty(CharStack *s)
Checks if character stack is empty

3. void pushChar(CharStack *s, char ch)
Pushes a character onto the stack

4. char popChar(CharStack *s)
Pops and returns top character

5. char peekChar(CharStack *s)
Returns top character without removing it

For Integers:
6. void initIntStack(IntStack *s)
Initializes integer stack

7. bool isIntStackEmpty(IntStack *s)
Checks if integer stack is empty

8. void pushInt(IntStack *s, int value)
Pushes an integer onto the stack

9. int popInt(IntStack *s)
Pops and returns top integer



10. bool isOperator(char ch)
Checks if character is one of: +, -, *, /, ^
Returns true for operators, false otherwise

11. int precedence(char op)
Returns precedence level of operator
Levels: +/- (1), */% (2), ^ (3)

Conversion from infix to postfix
12. void infixToPostfix(char *infix, char *postfix)
Purpose: Converts infix expression to postfix notation
Algorithm:
Scan infix expression left to right
If operand: append to postfix
If '(': push to stack
If ')': pop until '(' and append to postfix
If operator: pop operators with higher/equal precedence, then push current operator
After scan: pop all remaining operators
Parameters: Input infix string, output postfix string


13. int performOperation(int operand1, int operand2, char operator)
Purpose: Performs arithmetic operation on two operands
Returns: Result of operation
Handles: +, -, *, /, ^ (power)


14. int evaluatePostfix(char *postfix)
Purpose: Evaluates postfix expression and returns result
Algorithm:
Scan postfix left to right
If operand: push to integer stack
If operator: pop two operands, perform operation, push result
Final value on stack is the result
Returns: Final computed value

main() method organization
-Declaration of infix and postfix character arrays
-Test Case Conversion
-Conversion and evaluation of postfix expression

**Output**
Test Cases:
Infix                Postfix                   Result
--------------------------------------------------------
5+8*6                5 8 6 * +                 53
5+3*2-8/4            5 3 2 * + 8 4 / -         9
(5+9)*2              5 9 + 2 *                 28
2^3+4*5              2 3 ^ 4 5 * +             28
10+20*30             1 0 2 0 3 0 * +           0