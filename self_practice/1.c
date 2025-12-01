// sum of polynomials using array

#include <stdio.h>
struct Poly{
    int coeff;
    int exp;
};

void displayPoly(struct Poly p[], int s){
    for (int i=0;i<s;i++){
        printf("%d^%d", p[i].coeff, p[i].exp);
        if(i!=s-1){
            printf("+");
        }
    }
    printf("\n");
}

int addPoly(struct Poly p1[], int s1, struct Poly p2[], int s2, struct Poly r[]){
    int i=0,j=0,k=0;
    while(i<s1 && j<s2){
        if(p1[i].exp > p2[j].exp){
            r[k++]=p1[i++];
        }
        else if(p1[i].exp < p2[j].exp){
            r[k++]=p2[j++];
        }
        else{
            r[k].exp=p1[i].exp;
            r[k].coeff=p1[i].coeff + p2[j].coeff;
            i++;j++;k++;
        }
    }
    while(i<s1){
        r[k++]=p1[i++];
    }
    while(j<s2){
        r[k++]=p2[j++];
    }
    return k;
}

int main(){
    struct Poly p1[]={{63,3},{54,2},{56,1}};
    struct Poly p2[]={{55,3},{91,2},{23,1}};

    struct Poly r[20];

    int result= addPoly(p1,3,p2,3,r);

    printf("Polynomial 1:\n");
    displayPoly(p1,3);

    printf("Polynomial 2:\n");
    displayPoly(p2,3);

    printf("Resultant Polynomial after addition:\n");
    displayPoly(r,result);

    return 0;

}
