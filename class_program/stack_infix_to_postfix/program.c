#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

char stack[MAX];
int top = -1;

int evalStack[MAX];
int evalTop = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {  
            postfix[k++] = ch;  
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();  
        } 
        else {  
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
}

void evalPush(int n) {
    evalStack[++evalTop] = n;
}

int evalPop() {
    return evalStack[evalTop--];
}

int evaluatePostfix(char postfix[]) {
    int i, op1, op2;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isalnum(ch)) {
            int val;
            printf("Enter value of %c: ", ch);
            scanf("%d", &val);
            evalPush(val);
        } else {
            op2 = evalPop();
            op1 = evalPop();

            switch (ch) {
                case '+': evalPush(op1 + op2); break;
                case '-': evalPush(op1 - op2); break;
                case '*': evalPush(op1 * op2); break;
                case '/': evalPush(op1 / op2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < op2; j++) res *= op1;
                    evalPush(res);
                    break;
                }
            }
        }
    }

    return evalPop();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (use variables like a,b,c): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
