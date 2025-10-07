#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; 
        } else if (isOperator(infix[i])) {
            while (top >= 0 && isOperator(stack[top]) &&
                   (infix[i] == '+' || infix[i] == '-') && 
                   (stack[top] == '*' || stack[top] == '/')) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* constructExpressionTree(char* postfix) {
    struct Node* stack[MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            stack[++top] = createNode(c);
        } else if (isOperator(c)) {
            struct Node* node = createNode(c);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}

void printPostfix(struct Node* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    
    struct Node* root = constructExpressionTree(postfix);
    
    printf("Postfix Expression (from tree): ");
    printPostfix(root);
    printf("\n");
    
    return 0;
}
