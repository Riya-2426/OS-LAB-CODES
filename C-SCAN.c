#include <stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 199
int main() {
    int queue[20], n, head, temp;
    int total_head_movement = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter the disk queue elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    queue[n] = head;
    n++;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    int head_index;
    for(int i = 0; i < n; i++) {
        if(queue[i] == head) {
            head_index = i;
            break;
        }
    }
    printf("\nC-SCAN Sequence of head movement:\n");
    for(int i = head_index; i < n; i++) {
        printf("%d --> ", queue[i]);
        if(i > head_index)
            total_head_movement += abs(queue[i] - queue[i-1]);
    }
    if(queue[n-1] != HIGH) {
        total_head_movement += abs(HIGH - queue[n-1]); 
        total_head_movement += HIGH - LOW;             
        printf("HIGH --> LOW --> ");
    }
    for(int i = 0; i < head_index; i++) {
        printf("%d --> ", queue[i]);
        if(i == 0)
            total_head_movement += abs(queue[i] - LOW);
        else
            total_head_movement += abs(queue[i] - queue[i-1]);
    }
    printf("END\n");
    printf("\nTotal head movement = %d\n", total_head_movement);
    return 0;
}
