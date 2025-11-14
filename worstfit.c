#include <stdio.h>
int main() {
    int blockSize[10], processSize[10], blockNo, processNo;
    int allocation[10];  
    int i, j;
    printf("Enter number of memory blocks: ");
    scanf("%d", &blockNo);
    printf("Enter size of each block:\n");
    for(i = 0; i < blockNo; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("\nEnter number of processes: ");
    scanf("%d", &processNo);
    printf("Enter size of each process:\n");
    for(i = 0; i < processNo; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1; 
    }
    for(i = 0; i < processNo; i++) {
        int worstIdx = -1;
        for(j = 0; j < blockNo; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i]; 
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < processNo; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
