#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
struct p
{
int pid;
int at;
int bt;
int ct,wt,tat,rt,st;
};
int findmax(int a,int b)
{
return a>b?a:b;
}
int findmin(int a,int b)
{
return a<b?a:b;
}
int main()
{
int n;
bool is_compl[100]={false},is_1process=true;
int current_time=0;
int completed=0;
printf("Enter number of processes: ");
scanf("%d",&n);
struct p arr[n];
int sum_tat=0,sum_wt=0,sum_rt=0,it=0,prev=0,length_cycle;
float cpu_util;
int max_comp_time,min_arrival_time;
for(int i=0;i<n;i++)
{
printf("Enter Process %d Arrival Time: ",i);
scanf("%d",&arr[i].at);
arr[i].pid=i;
}
for(int i=0;i<n;i++)
{
printf("Enter Process %d Burst Time: ",i);
scanf("%d",&arr[i].bt);
}
while(completed!=n)
{
int min_index=-1;
int minimum=INT_MAX;
for(int i=0;i<n;i++)
{
if(arr[i].at<=current_time && is_compl[i]==false)
{
if(arr[i].bt<minimum)
{
minimum=arr[i].bt;
min_index=i;
}
if(arr[i].bt==minimum)
{
if(arr[i].at<arr[min_index].at)
{minimum=arr[i].bt;
min_index=i;
}}}}
if(min_index==-1)
{
current_time++;
}
else
{
arr[min_index].st=current_time;
arr[min_index].ct=arr[min_index].st+arr[min_index].bt;
arr[min_index].tat=arr[min_index].ct-arr[min_index].at;
arr[min_index].wt=arr[min_index].tat-arr[min_index].bt;
arr[min_index].rt=arr[min_index].wt;
sum_tat+=arr[min_index].tat;
sum_wt+=arr[min_index].wt;
sum_rt+=arr[min_index].rt;
it+=(is_1process==true)?0:(arr[min_index].st-prev);
completed++;
is_compl[min_index]=true;
current_time=arr[min_index].ct;
prev=current_time;
is_1process=false;
}
}
max_comp_time=INT_MIN;
min_arrival_time=INT_MAX;
for(int i=0;i<n;i++)
{
max_comp_time=findmax(max_comp_time,arr[i].ct);
min_arrival_time=findmin(min_arrival_time,arr[i].at);
}
length_cycle=max_comp_time-min_arrival_time;
printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
for(int i=0;i<n;i++)
printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
printf("\n");
cpu_util=(float)(length_cycle-it)/length_cycle;
printf("\nAverage Turn Around time= %f",(float)sum_tat/n);
printf("\nAverage Waiting Time= %f",(float)sum_wt/n);
printf("\nAverage Response Time= %f",(float)sum_rt/n);
printf("\nThroughput= %f",n/(float)length_cycle);
printf("\nCPU UTilization= %f",cpu_util*100);
return 0;
}

