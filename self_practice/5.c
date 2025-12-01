//Implement Circular Queue using arrays.
#include <stdio.h>
#define size 4
int cq[size];
int f=-1, r=-1;
void display(int a[], int f, int r){
    printf("Elements:");
    if(f==-1){
        printf(" EMPTY\n");
        return;
    }
    for(int i=f;i<=r;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void in(int val){
    if((f==0 && r==size-1) && (f==(r+1)%size)){
        printf("\nOverflow\n\n");
    }else{
        if(f==-1){
            f=r=0;
        }else{
            r=(r+1)%size;
        }
        cq[r]=val;
        printf("\nInserted %d\n", val);
        display(cq,f,r);
    }
    
}

void del(){
    if(f==-1){
        printf("\nUnderflow\n\n");
    }else{
        printf("Deleted: %d\n", cq[f]); 
        if (f == r) {
            f = r = -1; 
        }else{ 
            f = (f + 1) % size;
        }
    }
}

void circularQueue(){
    del();
    in(10);
    in(20);
    in(30); 
    in(40);
    in(50);
    del();
}

int main(){
    printf("\nCIRCULAR QUEUE Implementation using Arrays\n\n");
    circularQueue();
    display(cq,f,r);
    return 0;
}