#include <stdio.h>

struct Poly {
    int coef;
    int exp;
};

void inputPolynomial(struct Poly p[], int n) {
  printf("Enter coefficient and exponent of polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].coef);
        scanf("%d", &p[i].exp);
    }
}

void displayPolynomial(struct Poly p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].exp != 0)
             printf("%dx^%d", p[i].coef, p[i].exp);

        else
            printf("%d", p[i].coef);
           
        if (i != n - 1)
            printf(" + ");
    }
    printf("\n");
}


int addPolynomials(struct Poly p1[], int n1, struct Poly p2[], int n2, struct Poly sum[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) {
            sum[k].coef = p1[i].coef;
            sum[k].exp = p1[i].exp;
            i++,k++;
        } else if (p1[i].exp < p2[j].exp) {
            sum[k].coef = p2[i].coef;
            sum[k].exp = p2[i].exp;
            j++,k++;
        } else {
            sum[k].exp = p1[i].exp;
            sum[k].coef = p1[i].coef + p2[j].coef;
            i++; j++; k++;
        }
    }

   
    while (i < n1) {
        sum[k].coef = p1[i].coef;
        sum[k].exp = p1[i].exp;
        i++,k++;
    }
    while (j < n2) {
        sum[k].coef = p2[i].coef;
        sum[k].exp = p2[i].exp;
        j++,k++;
    }

    return k; 
}

int main() {
    int n1, n2, nsum;
    struct Poly p1[10], p2[10], sum[20];

    printf("Enter number of terms for polynomial1: ");
    scanf("%d", &n1);
    inputPolynomial(p1, n1);
    printf("Displaying number of terms for polynomial1: ");
    displayPolynomial(p1,n1);

    printf("Enter number of terms for polynomial2: ");
    scanf("%d", &n2);
    inputPolynomial(p2, n2);
    printf("Displaying number of terms for polynomial2: ");
    displayPolynomial(p2,n2);

    nsum = addPolynomials(p1, n1, p2, n2, sum);

    printf("Sum of polynomials:\n");
    displayPolynomial(p1,n1);
    printf("+\n");
    displayPolynomial(p2,n2);
    printf("=\n");
    displayPolynomial(sum, nsum);

    return 0;
}
