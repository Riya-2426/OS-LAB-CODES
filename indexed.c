#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 20
#define MAX_FILES 10

struct File {
    char name[20];
    int noOfBlocks;
    int* indexBlock; 
};

int main() {
    struct File files[MAX_FILES];
    int n, i, j;
    char search[20];
    printf("Enter number of files: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nEnter file %d name: ", i + 1);
        scanf(" %19s", files[i].name);
        printf("Enter number of blocks in file %s: ", files[i].name);
        scanf("%d", &files[i].noOfBlocks);
        files[i].indexBlock = (int*)malloc(files[i].noOfBlocks * sizeof(int));
        printf("Enter the block numbers for file %s: ", files[i].name);
        for(j = 0; j < files[i].noOfBlocks; j++) {
            scanf("%d", &files[i].indexBlock[j]);
        }
    }
    printf("\nFile Name\tNo. of Blocks\tIndex Block (Block Numbers)\n");
    printf("----------------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        printf("%-10s\t%-13d\t", files[i].name, files[i].noOfBlocks);
        for(j = 0; j < files[i].noOfBlocks; j++) {
            printf("%d", files[i].indexBlock[j]);
            if(j != files[i].noOfBlocks - 1) printf(" -> ");
        }
        printf("\n");
    }
    printf("\nEnter the file name to search: ");
    scanf(" %19s", search);
    int found = 0;
    for(i = 0; i < n; i++) {
        if(strcmp(search, files[i].name) == 0) {
            found = 1;
            printf("\nFile Found!\n");
            printf("File Name      : %s\n", files[i].name);
            printf("No. of Blocks  : %d\n", files[i].noOfBlocks);
            printf("Index Block    : ");
            for(j = 0; j < files[i].noOfBlocks; j++) {
                printf("%d", files[i].indexBlock[j]);
                if(j != files[i].noOfBlocks - 1) printf(" -> ");
            }
            printf("\n");
            break;
        }
    }
    if(!found) {
        printf("\nFile not found.\n");
    }
    for(i = 0; i < n; i++) {
        free(files[i].indexBlock);
    }
    return 0;
}
