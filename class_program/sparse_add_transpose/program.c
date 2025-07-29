#include <stdio.h>

#define MAX 100

void inputSparseMatrix(int r, int c, int x[r][c]) {
    printf("Enter the values of sparse matrix (%dx%d):\n", r, c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &x[i][j]);
        }
    }
}

void displaySparseMatrix(int r, int c, int x[r][c]) {
    printf("Matrix (%dx%d):\n", r, c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
}

int convertToSparse(int r, int c, int x[r][c], int sparse[MAX][3]) {
    int k = 1;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(x[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = x[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = k - 1;
    return k; 
}

void printSparse(int sparse[MAX][3], int total) {
    printf("Sparse matrix:\n");
    for(int i = 0; i < total; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int addSparse(int s1[MAX][3], int s2[MAX][3], int result[MAX][3]) {
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        printf("Error: Matrices dimensions do not match.\n");
        return 0;
    }

    int i = 1, j = 1, k = 1;
    result[0][0] = s1[0][0];
    result[0][1] = s1[0][1];

    while (i <= s1[0][2] && j <= s2[0][2]) {
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1]) {
            result[k][0] = s1[i][0];
            result[k][1] = s1[i][1];
            result[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        } else if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            result[k][0] = s1[i][0];
            result[k][1] = s1[i][1];
            result[k][2] = s1[i][2];
            i++; k++;
        } else {
            result[k][0] = s2[j][0];
            result[k][1] = s2[j][1];
            result[k][2] = s2[j][2];
            j++; k++;
        }
    }

    while(i <= s1[0][2]) {
        result[k][0] = s1[i][0];
        result[k][1] = s1[i][1];
        result[k][2] = s1[i][2];
        i++; k++;
    }
    while(j <= s2[0][2]) {
        result[k][0] = s2[j][0];
        result[k][1] = s2[j][1];
        result[k][2] = s2[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
    return k;
}

int transposeSparse(int src[MAX][3], int dest[MAX][3]) {
    int rowTerms[MAX] = {0}, startPos[MAX] = {0};
    int rows = src[0][0];
    int cols = src[0][1];
    int numTerms = src[0][2];

    dest[0][0] = cols;
    dest[0][1] = rows;
    dest[0][2] = numTerms;

    for (int i = 1; i <= numTerms; i++)
        rowTerms[src[i][1]]++;

    startPos[0] = 1;
    for (int i = 1; i < cols; i++)
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];

    for (int i = 1; i <= numTerms; i++) {
        int col = src[i][1];
        int pos = startPos[col];
        dest[pos][0] = src[i][1];
        dest[pos][1] = src[i][0];
        dest[pos][2] = src[i][2];
        startPos[col]++;
    }

    return numTerms + 1;
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns of Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    inputSparseMatrix(r1, c1, a);
    displaySparseMatrix(r1, c1, a);

    int s1[MAX][3];
    int t1 = convertToSparse(r1, c1, a, s1);
    printSparse(s1, t1);

    printf("Enter rows and columns of Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    int b[r2][c2];
    inputSparseMatrix(r2, c2, b);
    displaySparseMatrix(r2, c2, b);

    int s2[MAX][3];
    int t2 = convertToSparse(r2, c2, b, s2);
    printSparse(s2, t2);

    int result[MAX][3];
    int t3 = addSparse(s1, s2, result);
    if (t3 != 0) {
        printf("\nSum of Sparse Matrices:\n");
        printSparse(result, t3);

        int transposed[MAX][3];
        int t4 = transposeSparse(result, transposed);
        printf("\nTransposed Sparse Matrix:\n");
        printSparse(transposed, t4);
    }
    
    return 0;
}

