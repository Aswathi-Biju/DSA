
#include<stdio.h>

int binarySearch(int arr[], int n, int key, int *steps){
    int l=0;
    int r=n-1;
    while(l<=r){
        (*steps)++;
        int m = (l+r)/2;
        if(arr[m]==key)
            return m;
        if(arr[m]<key)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}

int main(){
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key=23;
    int steps=0;
    int index = binarySearch(arr,10,key,&steps);

    if(index!=-1){
        printf("Item %d found at index %d\n", key, index);
    }else{
        printf("Item %d not found\n", key);
    }

    int space = sizeof(arr) + 4*sizeof(int);
    printf("Space Complexity: %d bytes\n", space);
    printf("Time Complexity: %d", steps);
    return 0;
}