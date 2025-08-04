#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
int pid1,pid2;
pid1=fork();
if(pid1<0)
{
printf("Fork Failed!\n");
return 1;
}
else if(pid1==0)
{
printf("CHILD PROCESS 1 (PID: %d):Listing Files of System...\n",getpid());
execlp("ls","ls","-l",(char *)NULL);
exit(0);
}
else{
wait(NULL);
printf("Parent Process (PID: %d)\n",getpid());
pid2=fork();
if(pid2<0)
{
printf("Fork Failed!!");
return 1;
}
else if(pid2==0)
{
printf("CHILD PROCESS 2(PID:%d)\n",getpid());
sleep(5);
printf("CHILD PROCESS DONE!!\n");
exit(0);
}
else{
printf("Parent Process(PID:%d)EXITING..!!\n",getpid());
exit(0);
}
}
}

