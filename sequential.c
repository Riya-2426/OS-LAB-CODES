#include <stdio.h>
#include <string.h>
struct file {
    char name[20];
    int startBlock;
    int noOfBlocks;
    int blocks[20];
};
int main() {
    struct file files[10];
    int n, i, j;
    char search[20];
    int found = 0;
    printf("Enter number of files : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nEnter file %d name : ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter starting block of file %d : ", i + 1);
        scanf("%d", &files[i].startBlock);
        printf("Enter no of blocks in file %d : ", i + 1);
        scanf("%d", &files[i].noOfBlocks);

        for(j = 0; j < files[i].noOfBlocks; j++) {
            files[i].blocks[j] = files[i].startBlock + j;
        }
    }
    printf("\nFile Name\tStart block\tNo. of blocks\tBlocks occupied\n");
    for(i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t", files[i].name, files[i].startBlock, files[i].noOfBlocks);
        for(j = 0; j < files[i].noOfBlocks; j++) {
            printf("%d", files[i].blocks[j]);
            if(j != files[i].noOfBlocks - 1)
                printf(", ");
        }
        printf("\n");
    }
    printf("\nEnter the file name to be searched : ");
    scanf("%s", search);
    found = 0;
    for(i = 0; i < n; i++) {
        if(strcmp(search, files[i].name) == 0) {
            found = 1;
            printf("\nFile Name : %s", files[i].name);
            printf("\nStart Block : %d", files[i].startBlock);
            printf("\nNo. of Blocks : %d", files[i].noOfBlocks);
            printf("\nBlocks occupied : ");
            for(j = 0; j < files[i].noOfBlocks; j++) {
                printf("%d", files[i].blocks[j]);
                if(j != files[i].noOfBlocks - 1)
                    printf(", ");
            }
            printf("\n");
            break;
        }
    }
    if(!found)
        printf("\nFile not found.\n");
    return 0;
}
