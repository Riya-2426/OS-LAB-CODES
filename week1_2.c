#include<stdio.h>
#include<unistd.h>
int main()
{
int pid=fork();
if(pid<0)
{
printf("Fork Failed!!");
return 1;
}
else if(pid==0)
{
printf("This is Child Process!!!\n");
printf("PID: %d  ParentID: %d\n",getpid(),getppid());
}
else
{
printf("This is Parent Process!!!\n");
printf("PID: %d\n",getpid());
}
return 0;
}

