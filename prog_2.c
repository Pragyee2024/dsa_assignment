//Infix to Postfix Conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

// Stack for characters (+,-,*,/,^)
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

// Stack for integers (operands during evaluation)
typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;

// Character Stack Operations
void initCharStack(CharStack *s) {
    s->top = -1;
}

bool isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

void pushChar(CharStack *s, char ch) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

char popChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

char peekChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Integer Stack Operations
void initIntStack(IntStack *s) {
    s->top = -1;
}

bool isIntStackEmpty(IntStack *s) {
    return s->top == -1;
}

void pushInt(IntStack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int popInt(IntStack *s) {
    if (isIntStackEmpty(s)) {
        printf("Stack underflow!\n");
        return 0;
    }
    return s->items[(s->top)--];
}

// Check if character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Get precedence of operator
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // Skip whitespace
        if (isspace(ch)) {
            continue;
        }
        
        // If operand (digit or letter), add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
            postfix[j++] = ' ';  // Add space separator
        }
        // If '(', push to stack
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!isCharStackEmpty(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            if (!isCharStackEmpty(&s)) {
                popChar(&s);  // Remove '('
            }
        }
        // If operator
        else if (isOperator(ch)) {
            while (!isCharStackEmpty(&s) && 
                   peekChar(&s) != '(' && 
                   precedence(peekChar(&s)) >= precedence(ch)) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            pushChar(&s, ch);
        }
    }
    
    // Pop remaining operators
    while (!isCharStackEmpty(&s)) {
        postfix[j++] = popChar(&s);
        postfix[j++] = ' ';
    }
    
    postfix[j] = '\0';
}

// Perform arithmetic operation
int performOperation(int operand1, int operand2, char operator) {
    switch(operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            return operand1 / operand2;
        case '^':
            return (int)pow(operand1, operand2);
        default:
            return 0;
    }
}

// Evaluate postfix expression
int evaluatePostfix(char *postfix) {
    IntStack s;
    initIntStack(&s);
    
    char *token = strtok(postfix, " ");
    
    while (token != NULL) {
        // If token is a number
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            pushInt(&s, atoi(token));
        }
        // If token is an operator
        else if (isOperator(token[0]) && strlen(token) == 1) {
            int operand2 = popInt(&s);
            int operand1 = popInt(&s);
            int result = performOperation(operand1, operand2, token[0]);
            pushInt(&s, result);
        }
        
        token = strtok(NULL, " ");
    }
    
    return popInt(&s);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    printf("=== Infix to Postfix Converter and Evaluator ===\n\n");
    
    // Test cases
    char *testCases[] = {
        "5+8*6",
        "5+3*2-8/4",
        "(5+9)*2",
        "2^3+4*5",
        "10+20*30"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    printf("Test Cases:\n");
    printf("%-20s %-25s %s\n", "Infix", "Postfix", "Result");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < numTests; i++) {
        strcpy(infix, testCases[i]);
        infixToPostfix(infix, postfix);
        
        // For evaluation, need a copy since strtok modifies the string
        char postfixCopy[MAX_SIZE];
        strcpy(postfixCopy, postfix);
        
        int result = evaluatePostfix(postfixCopy);
        
        printf("%-20s %-25s %d\n", testCases[i], postfix, result);
    }
    
    return 0;
}