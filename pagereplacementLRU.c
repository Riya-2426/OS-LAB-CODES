#include<stdio.h>
int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for(i = 1; i < n; i++) {
        if(time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}
int main() {
    int pages[30], frames[10], time[10];
    int n, f, i, j, pos, flag1, flag2, pagefaults = 0, counter = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    printf("\n Page Replacement Process:\n");
    for(i = 0; i < n; i++) {
        flag1 = flag2 = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;  
                flag1 = flag2 = 1;
                printf("For Page %d: No page fault\n", pages[i]);
                break;
            }
        }
        if(flag1 == 0) {
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    counter++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    pagefaults++;
                    flag2 = 1;
                    printf("For Page %d: ", pages[i]);
                    for(int k = 0; k < f; k++) {
                        if(frames[k] != -1)
                            printf("%d ", frames[k]);
                        else
                            printf("- ");
                    }
                    printf("(Page Fault)\n");
                    break;
                }
            }
        }
        if(flag2 == 0) {
            pos = findLRU(time, f);
            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            pagefaults++;
            printf("For Page %d: ", pages[i]);
            for(int k = 0; k < f; k++) {
                printf("%d ", (frames[k] != -1) ? frames[k] : -1);
            }
            printf("(Page Fault)\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", pagefaults);
    return 0;
}
