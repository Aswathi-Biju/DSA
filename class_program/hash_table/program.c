#include <stdio.h>

#define SIZE 10

int main() {
    int hashTable[SIZE];
    int keys[SIZE];
    int n, key, index;

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    for (int i = 0; i < n; i++) {
        key = keys[i];
        index = key % SIZE;

        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
    }

    printf("\nHash Table (Index : Value)\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d : ", i);
        if (hashTable[i] != -1)
            printf("%d\n", hashTable[i]);
        else
            printf("empty\n");
    }

    return 0;
}
