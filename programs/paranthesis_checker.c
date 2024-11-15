#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack Overflow \n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow \n");
        return '\0';
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char *expr) {
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch); 
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                return 0; 
            }
            char topChar = pop(); 
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0; 
            }
        }
    }
    return isEmpty(); 
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);


    if (isBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
