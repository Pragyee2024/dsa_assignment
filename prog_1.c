//Checking balanced parentheses using stack in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

//Structure for stack
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;                    //Initializing top of stack to -1
}

bool isEmpty(Stack *s){             //Condition to check if stack is empty
    return s->top == -1;
}

bool isFull(Stack *s) {             //Condition to check if stack is full
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char ch) {         //Push operation
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

char pop(Stack *s) {                //Pop operation
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {           //Peek operation
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');       //Check opening brackets
}

bool isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');       //Check closing brackets
}

bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

bool isBalanced(char *expression) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        
        if (isOpeningBracket(ch)) {             // If opening bracket, push to stack
            push(&s, ch);
        }
        
        else if (isClosingBracket(ch)) {        // If closing bracket, check for matching opening bracket
            if (isEmpty(&s)) {
                return false;  
            }
            char top = pop(&s);
            if (!isMatchingPair(top, ch)) {
                return false;                   // Mismatched brackets
            }
        }
    }
    
    return isEmpty(&s);
}

int main() {
    // Test expressions
    char *expressions[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);
    
    printf(" Balanced Parentheses Checker \n\n");
    
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i]);
        
        if (isBalanced(expressions[i])) {
            printf("Result: Balanced\n");
        } else {
            printf("Result: Not Balanced\n");
        }
        printf("\n");
    }
    
    return 0;
}