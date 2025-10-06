#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

struct Node* constructExpressionTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            struct Node* node = createNode(c);
            push(node);
        } else if (isOperator(c)) {
            struct Node* node = createNode(c);
            struct Node* right = pop();
            struct Node* left = pop();
            node->right = right;
            node->left = left;
            push(node);
        }
    }
    return pop();
}

void printPrefix(struct Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(struct Node* root) {
    if (root == NULL) return;
    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c", root->data);
}

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = constructExpressionTree(postfix);

    printf("\nPrefix Expression: ");
    printPrefix(root);

    printf("\nPostfix Expression: ");
    printPostfix(root);

    return 0;
}
