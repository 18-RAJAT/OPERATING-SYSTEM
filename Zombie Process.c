#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
    pid_t pid=fork();
    if(pid>0)
    {
        printf("Parent id = %d child id = %d",getppid(),getpid());
        sleep(20);
        // printf("")
    }
    else
    {
        printf("child process become zombie process");
        exit(0);
    }
}