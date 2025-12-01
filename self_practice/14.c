//u r given a hash table with 10 slots (indexed 0 to 9), provided with set of integer that need to be inserted into the hash table using a hash function.
#include<stdio.h>
int main(){
    int hashTable[10];
    int values[6] = {15, 25, 34, 42, 7, 17};
    for(int i=0; i<10; i++){
        hashTable[i]=0;
    }
    for(int i=0; i<6; i++){
        int key = values[i];
        int index = key % 10;
        while(hashTable[index]!=0){
            index = (index + 1) % 10;
        }
        hashTable[index] = key;
    }
    printf("HASH TABLE\n");
    for(int i=0; i<10; i++){
        printf("%d -> %d\n",i,hashTable[i]);
    }
    return 0;
}