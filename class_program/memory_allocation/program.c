#include <stdio.h> 
#define MAX_BLOCKS 10 
#define MAX_PROCESSES 10 
int blockSize[MAX_BLOCKS]; 
int m; 
void resetBlocks(int originalBlocks[]) { 
for(int i = 0; i < m; i++) { 
blockSize[i] = originalBlocks[i]; 
} 
} 
void firstFit(int processSize[], int n) { 
int allocation[n]; 
for(int i = 0; i < n; i++) 
allocation[i] = -1; 
for(int i = 0; i < n; i++) { 
for(int j = 0; j < m; j++) { 
if(blockSize[j] >= processSize[i]) { 
allocation[i] = j; 
blockSize[j] -= processSize[i]; 
break; 
} 
} 
} 
printf("\nFirst Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n"); 
for(int i = 0; i < n; i++) { 
printf(" %d\t\t%d\t\t", i + 1, processSize[i]); 
if(allocation[i] != -1) 
printf("%d\n", allocation[i] + 1); 
else 
printf("Not Allocated\n"); 
} 
} 
void bestFit(int processSize[], int n) { 
int allocation[n]; 
for(int i = 0; i < n; i++) 
allocation[i] = -1; 
    for(int i = 0; i < n; i++) { 
        int bestIdx = -1; 
        for(int j = 0; j < m; j++) { 
            if(blockSize[j] >= processSize[i]) { 
 
 
 
 
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) { 
                    bestIdx = j; 
                } 
            } 
        } 
        if(bestIdx != -1) { 
            allocation[i] = bestIdx; 
            blockSize[bestIdx] -= processSize[i]; 
        } 
    } 
 
    printf("\nBest Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n"); 
    for(int i = 0; i < n; i++) { 
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]); 
        if(allocation[i] != -1) 
            printf("%d\n", allocation[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    } 
} 
 
void worstFit(int processSize[], int n) { 
    int allocation[n]; 
    for(int i = 0; i < n; i++) 
        allocation[i] = -1; 
 
    for(int i = 0; i < n; i++) { 
        int worstIdx = -1; 
        for(int j = 0; j < m; j++) { 
            if(blockSize[j] >= processSize[i]) { 
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) { 
                    worstIdx = j; 
                } 
            } 
        } 
        if(worstIdx != -1) { 
            allocation[i] = worstIdx; 
            blockSize[worstIdx] -= processSize[i]; 
        } 
    } 
 
 
 
 
    printf("\nWorst Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n"); 
    for(int i = 0; i < n; i++) { 
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]); 
        if(allocation[i] != -1) 
            printf("%d\n", allocation[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    } 
} 
 
 
void garbageCollector(int originalBlocks[]) { 
    // Resets block sizes to original 
    resetBlocks(originalBlocks); 
    printf("\nGarbage collector executed. Memory blocks are reset.\n"); 
} 
 
int main() { 
    int processSize[MAX_PROCESSES]; 
    int n; // number of processes 
    int originalBlocks[MAX_BLOCKS]; 
 
    printf("Enter the number of memory blocks: "); 
    scanf("%d", &m); 
    if(m > MAX_BLOCKS || m <= 0) { 
        printf("Invalid number of blocks.\n"); 
        return 1; 
    } 
 
    printf("Enter the size of each memory block:\n"); 
    for(int i = 0; i < m; i++) { 
        scanf("%d", &blockSize[i]); 
        originalBlocks[i] = blockSize[i];   
    } 
 
    printf("Enter the number of processes: "); 
    scanf("%d", &n); 
    if(n > MAX_PROCESSES || n <= 0) { 
        printf("Invalid number of processes.\n"); 
        return 1; 
    } 
 
    printf("Enter the size of each process:\n"); 
    for(int i = 0; i < n; i++) { 
        scanf("%d", &processSize[i]); 
    } 
 
 
 
 
 
 
    int choice; 
 
    while(1) { 
        printf("\n--- Memory Allocation Menu ---\n"); 
        printf("1. First Fit\n"); 
        printf("2. Best Fit\n"); 
        printf("3. Worst Fit\n"); 
        printf("4. Garbage Collector (Reset Memory)\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
 
 
 
 
        switch(choice) { 
            case 1: 
                resetBlocks(originalBlocks); 
                firstFit(processSize, n); 
                break; 
            case 2: 
                resetBlocks(originalBlocks); 
                bestFit(processSize, n); 
                break; 
            case 3: 
                resetBlocks(originalBlocks); 
                worstFit(processSize, n); 
                break; 
            case 4: 
                garbageCollector(originalBlocks); 
                break; 
            case 5: 
                printf("Exiting program.\n"); 
                return 0; 
            default: 
                printf("Invalid choice. Please select 1-5.\n"); 
        } 
    } 
 
    return 0; 
} 
