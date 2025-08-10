#include<stdio.h>
#include<stdlib.h>
struct p{
int pid;
int at;
int bt;
int ct;
float tat;
float wt;
int rt;
int st;
};
int compare(const void *p1,const void *p2)
{
int a=((struct p*)p1)->at;
int b=((struct p*)p2)->at;
if(a<b)
return -1;
else 
return 1;
}
int main()
{
int n;
float swt=0,stat=0;
float cu=0,throughput=0;
float awt=0,atat=0;
int sbt=0;
printf("Enter the number of processes: ");
scanf("%d",&n);
struct p arr[n];
for(int i=0;i<n;i++)
{
printf("For process %d",i+1);
arr[i].pid=i+1;
printf("Enter the value of AT and BT: ");
scanf("%d %d",&arr[i].at,&arr[i].bt);
}
qsort((void *)arr,n,sizeof(struct p),compare);
for(int i=0;i<n;i++)
{
if(i==0)
{
arr[i].ct=arr[i].at+arr[i].bt;
}
else if(arr[i-1].ct<=arr[i].at)
{
arr[i].ct=arr[i].at+arr[i].bt;
}
else{
arr[i].ct=arr[i-1].ct+arr[i].bt;
}
arr[i].tat=arr[i].ct-arr[i].at;
arr[i].wt=arr[i].tat-arr[i].bt;

sbt+=arr[i].bt;
swt+=arr[i].wt;
stat+=arr[i].tat;
arr[i].rt=arr[i].wt;
}
awt=swt/n;
atat=stat/n;
float max;
for(int i=0;i<n;i++)
{
arr[i].st=arr[i].rt+arr[i].at;
max=0;
if(arr[i].ct>max)
{
max=arr[i].ct;
}
}
cu=(sbt/max)*100;
throughput=n/max;
printf("\nPID\tAT\tBT\tST\tCT\tTAT\t\tWT\t\tRT\n");
for(int i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%f\t%f\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].st,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
}
printf("\nSum of Turn Around Time: %f\nAverage of Turn Around Time: %f\n",stat,atat);
printf("SUm of Waiting Time: %f\nAverage of Waiting Time: %f\nCPU Utilization: %f\nThroughput: %f",swt,awt,cu,throughput);
return 0;
}












































































