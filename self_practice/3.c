//Convert infix expression to postfix using stack.
#include<stdio.h>
#include<ctype.h>

int prec(char c){
    switch(c){
        case '^': return 3;
        case '*': case'/': return 2;
        case '+': case'-': return 1;
    }
    return 0;
}

int isOp(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

void infixToPostfix(char infix[], char postfix[]){
    char stack[100];
    int top=-1;
    int k=0;
    for (int i=0; infix[i]!='\0'; i++){
        if(isalpha(infix[i])){
            postfix[k++]=infix[i];
        }else if(infix[i]=='('){
            stack[++top]=infix[i];
        }else if(infix[i]==')'){
            while(top>=0 && stack[top]!='('){
                postfix[k++]=stack[top--];
            }top--;
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

int main(){
    char infix[]="a+b*(c^d-e)^(f+g*h)-i";
    char postfix[100];
    infixToPostfix(infix,postfix);
    printf("\nInfix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}