#include<stdio.h>
#include<unistd.h>
int main()
{
int pid=fork();
if(pid<0)
{
printf("Fork Failed!!!");
return 1;
}
else if(pid==0)
{
printf("I'm Child Process!! PID: %d\n",getpid());
}
else{
printf("I'm Parent Process!! PID: %d CHILD PID: %d\n",getpid(),pid);
}
return 0;
}
