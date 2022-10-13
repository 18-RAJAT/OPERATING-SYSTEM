#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
    pid_t pid=fork();
    if(pid>0)
    {
        printf("Parent process id=%d with child id=%d\n",getppid(),getpid());
    }
    else
    { 
        sleep(20);
        printf("Child process=%d and parent id=%d\n",getpid(),getppid());
    }
    return 0;
}