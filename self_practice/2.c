// Sum of two sparse matrices and transpose the resultant matrix

#include<stdio.h>
#include<stdlib.h>

void display(int x[][3], int s){
    for(int i=0;i<s;i++){
        printf("(%d,%d,%d)\n", x[i][0], x[i][1], x[i][2]);
    }
    printf("\n");
}

int add(int a[][3], int s, int b[][3], int c, int r[][3] ){
    int i=0,j=0,k=0;
    while(i<s && j<c){
        if(a[i][0]<b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1])){
            r[k][0]=a[i][0];
            r[k][1]=a[i][1];
            r[k][2]=a[i][2];
            i++, k++;
        }else if(a[i][0]>b[j][0] || (a[i][0]==b[j][0] && a[i][1]>b[j][1])){
            r[k][0]=b[j][0];
            r[k][1]=b[j][1];
            r[k][2]=b[j][2];
            j++,k++;
        }else{
            r[k][0]=a[i][0];
            r[k][1]=a[i][1];
            r[k][2]=a[i][2]+b[j][2];
            i++,j++,k++;
        }
    }

    while(i<s){
        r[k][0]=a[i][0];
        r[k][1]=a[i][1];
        r[k][2]=a[i][2];
        i++,k++;
    }

    while(j<c){
        r[k][0]=b[j][0];
        r[k][1]=b[j][1];
        r[k][2]=b[j][2];
        j++, k++;
    }

    return k;
}

void transpose(int r[][3], int s){
    for(int i=0; i<s; i++){
        int temp = r[i][0];
        r[i][0] = r[i][1];
        r[i][1] = temp;
    }

    for( int i=0; i<s-1; i++){
        for (int j=i+1; j<s; j++){
            if(r[j][0]<r[i][0] || (r[j][0]==r[i][0] && r[j][1]<r[i][1])){
                int t0 = r[i][0];
                r[i][0] = r[j][0];
                r[j][0] = t0;

                int t1 = r[i][1];
                r[i][1] = r[j][1];
                r[j][1] = t1;

                int t2 = r[i][2];
                r[i][2] = r[j][2];
                r[j][2] = t2;
                
            }
        }
    }

}

int main(){
    int a[][3]={{0,0,3},{1,0,7}, {1,1,4},{1,2,6}};
    int b[][3]={{0,1,2},{1,0,1}, {1,2,5}};
    printf("Matrix A (triplets):\n");
    display(a,4);
    printf("Matrix B (Triplets):\n");
    display(b,3);
    int r[10][3];
    int res= add(a,4,b,3,r);
    printf("Resultant matrix after addition:\n");
    display(r,res);
    printf("Transpose of resultant matrix:\n");
    transpose(r,res);
    display(r,res);
    return 0;
}