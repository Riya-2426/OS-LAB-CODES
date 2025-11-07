#include<stdio.h>
#include<stdlib.h>
int main()
{
    int pages[30],frames[10];
    int n,f,i,j,k=0,flag=0,pagefaults=0;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter the page reference string: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        frames[i]=-1;
    }
    printf("\n Page Replacement Process:\n");
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<f;j++)
        {
            if(frames[j]==pages[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frames[k]=pages[i];
            k=(k+1)%f;
            pagefaults++;
            printf("For Page %d: ",pages[i]);
            for(j=0;j<f;j++)
            {
                if(frames[j]!=-1)
                  printf("%d ",frames[j]);
                else
                  printf("- ");
            }
            printf("(Page Fault)\n");
        }
        else{
            printf("For Page %d: No page fault\n",pages[i]);
        }
    }
    printf("\nTotal Page Faults= %d\n",pagefaults);
    return 0;
}