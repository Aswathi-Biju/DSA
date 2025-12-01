//simulation of basic memory allocator and garbage collector using dll
#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

int blockSize[MAX_BLOCKS];
int m;

void resetBlocks(int originalBlocks[]) {
    for (int i = 0; i < m; i++)
        blockSize[i] = originalBlocks[i];
}

void firstFit(int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

    printf("\n--- First Fit Allocation ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%s\n", i + 1, processSize[i],
               allocation[i] != -1 ? (allocation[i]+1)+"\0" : "Not Allocated");
}

void bestFit(int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i] && (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]))
                bestIdx = j;

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\n--- Best Fit Allocation ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%s\n", i + 1, processSize[i],
               allocation[i] != -1 ? (allocation[i]+1)+"\0" : "Not Allocated");
}

void worstFit(int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i] && (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]))
                worstIdx = j;

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\n--- Worst Fit Allocation ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%s\n", i + 1, processSize[i],
               allocation[i] != -1 ? (allocation[i]+1)+"\0" : "Not Allocated");
}

void garbageCollector(int originalBlocks[]) {
    resetBlocks(originalBlocks);
    printf("\nGarbage collector executed. Memory blocks are reset.\n");
    printf("Current Memory Block Sizes:\n");
    for (int i = 0; i < m; i++)
        printf("Block %d: %d\n", i + 1, blockSize[i]);
}

int main() {
    // -------- Hardcoded memory blocks --------
    m = 5;
    int originalBlocks[MAX_BLOCKS] = {100, 500, 200, 300, 600};
    resetBlocks(originalBlocks);

    // -------- Hardcoded process sizes --------
    int n = 4;
    int processSize[MAX_PROCESSES] = {212, 417, 112, 426};

    // -------- Allocation Simulations --------
    resetBlocks(originalBlocks);
    firstFit(processSize, n);

    resetBlocks(originalBlocks);
    bestFit(processSize, n);

    resetBlocks(originalBlocks);
    worstFit(processSize, n);

    garbageCollector(originalBlocks);

    return 0;
}
