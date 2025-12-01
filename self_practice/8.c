//Create a binary tree for a given simple arithmetic expression and find the postfix equivalent.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char dat){
    struct Node* node = malloc(sizeof(struct Node));
    node->data = dat;
    node->left = node->right = NULL;
    return node;
}

int prec(char c){
    switch (c){
    case '^' : return 3;
    case '*' : case '/' : return 2;
    case '+' : case '-' : return 1; 
    }
    return 0;
}

int isOp(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

void infixToPostfix(char infix[], char postfix[]){
    char stack[100];
    int top=-1;
    int k=0;
    for(int i=0; infix[i]!='\0'; i++){
        if(isalpha(infix[i])){
            postfix[k++]=infix[i];
        }else if(infix[i]=='('){
            stack[++top]=infix[i];
        }else if(infix[i]==')'){
            while(top>=0 && stack[top]!='('){
                postfix[k++]=stack[top--];
            }
            top--;
        }else if(isOp(infix[i])){
            while(top>=0 && prec(stack[top])>=prec(infix[i]) && stack[top]!='('){
                postfix[k++] = stack[top--];
            }
            stack[++top]=infix[i];
        }
    }
    while(top>=0){
        postfix[k++]=stack[top--];  
    }
    postfix[k]='\0';
}

struct Node* createBinaryTree(char postfix[]){
    struct Node* stack[100];
    int top=-1;
    for(int i=0; postfix[i]!='\0'; i++){
        char c=postfix[i];
        if(isalpha(c)){
            stack[++top] = createNode(c);
        }else if(isOp(postfix[i])){
            struct Node* node = createNode(c);
            node->right=stack[top--];
            node->left=stack[top--];
            stack[++top]=node;
        }
    }
    return stack[top];
}

void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%c ", root->data);
    preorder(root->left);       
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);       
    postorder(root->right);
    printf("%c ", root->data);
}

int main(){
    char infix[]="a+b*(c^d-e)^(f+g*h)-i";
    char postfix[100];
    infixToPostfix(infix,postfix);
    printf("\nInfix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    printf("\nConverting Postfix Expression to Expression Tree...\n");

    struct Node* root = createBinaryTree(postfix);
    
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}