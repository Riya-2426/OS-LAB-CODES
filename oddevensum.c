//WAP to print the sum of even no.'s of array in parent process and odd no.'s sum in child process.
//Even no. sum should print first. (Concept of ORPHAN PROCESS...)
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
int evensum=0,oddsum=0,n;
printf("Enter number of elements: ");
scanf("%d",&n);
int arr[n];
printf("Enter elements of array: ");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
int pid=fork();
if(pid<0)
{
printf("Fork Failed!!\n");
return 1;
}
else if(pid==0)    //CHILD PROCESS...(ORPHAN CHILD)
{
wait(NULL);
for(int i=0;i<n;i++)
{
if(arr[i]%2!=0)
oddsum+=arr[i];
}
printf("Odd elements sum is: %d\n",oddsum);
exit(0);
}
else               //PARENT PROCESS...
{
for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
evensum+=arr[i];
}
printf("Even elements sum is: %d\n",evensum);
exit(0);
}
return 0;
}


