#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block {
    int blockNo;
    struct Block* next;
};

struct File {
    char name[20];
    int noOfBlocks;
    struct Block* first;
    struct Block* last;
};

int main() {
    struct File files[10];
    int n, i, j;
    char search[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file %d name: ", i + 1);
        scanf(" %19s", files[i].name);

        printf("Enter number of blocks in file %s: ", files[i].name);
        scanf("%d", &files[i].noOfBlocks);

        files[i].first = NULL;
        files[i].last = NULL;

        for (j = 0; j < files[i].noOfBlocks; j++) {
            int blockNo;
            printf("Enter block number %d: ", j + 1);
            scanf("%d", &blockNo);

            struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
            newBlock->blockNo = blockNo;
            newBlock->next = NULL;

            if (files[i].first == NULL) {
                files[i].first = newBlock;
                files[i].last = newBlock;
            } else {
                files[i].last->next = newBlock;
                files[i].last = newBlock;
            }
        }
    }

    // Display all files
    printf("\nFile Name\tNo. of Blocks\tBlocks\t\tFirst Block\tLast Block\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10s\t%-13d\t", files[i].name, files[i].noOfBlocks);

        struct Block* temp = files[i].first;
        while (temp != NULL) {
            printf("%d", temp->blockNo);
            if (temp->next != NULL) printf(" -> ");
            temp = temp->next;
        }

        printf("\t\t%d\t\t%d\n", files[i].first->blockNo, files[i].last->blockNo);
    }

    // Search for a file
    printf("\nEnter the file name to search: ");
    scanf(" %19s", search);

    for (i = 0; i < n; i++) {
        if (strcmp(search, files[i].name) == 0) {
            printf("\nFile Found!\n");
            printf("File Name      : %s\n", files[i].name);
            printf("No. of Blocks  : %d\n", files[i].noOfBlocks);
            printf("Blocks occupied: ");
            struct Block* temp = files[i].first;
            while (temp != NULL) {
                printf("%d", temp->blockNo);
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
            printf("\nFirst Block    : %d\n", files[i].first->blockNo);
            printf("Last Block     : %d\n", files[i].last->blockNo);
            break;
        }
    }

    return 0;
}
