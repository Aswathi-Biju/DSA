//Implement addition of polynomials using singly linked lists. 

#include<stdio.h>
#include<stdlib.h>
struct Poly{
    int coeff;
    int exp;
    struct Poly*next;
};

struct Poly* add(struct Poly* p1, struct Poly* p2){
    struct Poly* head= NULL;
    struct Poly* tail= NULL;
    while(p1 && p2){
        struct Poly* node = malloc(sizeof(struct Poly));
        if(p1->exp==p2->exp){
            node->coeff = p1->coeff + p2->coeff;
            node->exp = p1->exp;

            p1 = p1->next;
            p2 = p2->next;
        }else if(p1->exp > p2->exp){
            node->coeff = p1->coeff;
            node->exp = p1->exp;

            p1 = p1->next;
        }else{
            node->coeff = p2->coeff;
            node->exp = p2->exp;

            p2 = p2->next;
        }
        node->next=NULL;
        if(!head){
            head=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }
    while(p1){
        struct Poly* node = malloc(sizeof(struct Poly));
        node->coeff = p1->coeff;
        node->exp = p1->exp;
        node->next=NULL;
        if(!head){
            head=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
        p1 = p1->next;
    }

    while(p2){
        struct Poly* node = malloc(sizeof(struct Poly));
        node->coeff = p2->coeff;
        node->exp = p2->exp;
        node->next=NULL;
        if(!head){
            head=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
        p2 = p2->next;
    }
    return head;    
}

void print(struct Poly* p){
    while(p!=NULL){
        printf("%d^%d", p->coeff, p->exp);
        p=p->next;
        if(p!=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    struct Poly a1={66,4,NULL};
    struct Poly a2={47,3,NULL};
    struct Poly a3={23,2,NULL};
    struct Poly a4={12,1,NULL};
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;
    struct Poly* p1 = &a1;
    printf("\nPolynomial 1: ");
    print(p1);


    struct Poly b1={27,3,NULL};
    struct Poly b2={32,2,NULL};
    struct Poly b3={54,1,NULL};
    b1.next=&b2;
    b2.next=&b3;
    struct Poly* p2 = &b1;
    printf("\nPolynomial 2: ");
    print(p2);


    struct Poly* result = add(p1,p2);
    printf("\nResultant Polynomial after addition: ");
    print(result);


    return 0;
}