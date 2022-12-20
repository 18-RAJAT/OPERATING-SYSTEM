#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    //path1 is for ls command
    char *path1="/bin/ls";
    //path2 is for date command
    char *path2="/bin/date";

    int pid=fork();
    if(pid==0)
    {
        //child process
        //executing ls command
        execl(path1,path1,NULL);
    }
    else
    {
        //parent process
        //executing date command
        execl(path2,path2,NULL);
    }
}