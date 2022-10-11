#include <stdio.h>
#include<unistd.h>
#include<windows.h>
#define _XOPEN_SOURCE 600
#include <sys/types.h>
int main()
{
  fork();
//     int pid;
//   pid_t pid = fork();
    // printf("Hello World %d",pid);
    fork();
    printf("Hello World");
  return 0;
}