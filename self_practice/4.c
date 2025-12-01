#include <stdio.h>
#define size 3

void display(int a[], int f, int r){
    printf("Elements:");
    if(f > r){
        printf(" EMPTY\n");
        return;
    }
    for(int i=f;i<=r;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

// Queue functions
int q[size];
int fq=0, rq=-1;

void inQ(int val){
    if(rq==size-1){
        printf("Cannot insert %d->Queue Overflow\n",val);
    }else{
        q[++rq]=val;
        printf("Inserted %d in Queue\n",val);
        display(q,fq,rq);
        printf("\n");
    }
}

void delQ(){
    if(fq>rq){
        printf("Can't delete %d->Queue Underflow\n", q[fq]); 
    }else{
        int val=q[fq++];
        printf("Deleted %d from Queue\n",val);
        display(q,fq,rq);
        printf("\n");
    }
}

void queue(){
    delQ();
    inQ(10);
    inQ(20);
    inQ(30);
    inQ(40);
    delQ();
    inQ(50);
}

// Deque functions
int dq[size];
int fdq=0, rdq=-1;

void inFDQ(int val){
    if(fdq==0 && rdq==size-1){
        printf("Cannot insert %d at front->DEQUEUE Overflow\n",val);
    }else{
        if(fdq==-1){
            fdq=rdq=0;
            dq[fdq]=val;
        }else if(fdq>0){
            dq[--fdq]=val;
        }else{
            for(int i=rdq;i>=fdq;i--){
                dq[i+1]=dq[i];
            }
            dq[fdq]=val;
            rdq++;
        }
        printf("Inserted %d at front in DEQUEUE\n",val);
        display(dq,fdq,rdq);
        printf("\n");
    }
}

void inRDQ(int val){
    if(rdq==size-1){
        printf("Cannot insert %d at rear->DEQUEUE Overflow\n",val);
    }else{
        dq[++rdq]=val;
        printf("Inserted %d at rear in DEQUEUE\n",val);
        display(dq,fdq,rdq);
        printf("\n");
    }
}

void delFDQ(){
    if(fdq>rdq){
        printf("Can't delete from front->DEQUEUE Underflow\n");
    }else{
        int val=dq[fdq++];
        printf("Deleted %d from front in DEQUEUE\n",val);
        display(dq,fdq,rdq);
        printf("\n");
    }
}

void delRDQ(){
    if(fdq>rdq){
        printf("Can't delete from rear->DEQUEUE Underflow\n");
    }else{
        int val=dq[rdq--];
        printf("Deleted %d from rear in DEQUEUE\n",val);
        display(dq,fdq,rdq);
        printf("\n");
    }
}

void deque(){
    inRDQ(10);
    inRDQ(20);
    inFDQ(30);
    inFDQ(40);
    delFDQ();
    delRDQ();
}

int main(){
    printf("\nQueue Implementation using Arrays\n\n");
    queue();
    printf("\nDEQUEUE Implementation using Arrays\n\n");
    deque();
    return 0;
}
