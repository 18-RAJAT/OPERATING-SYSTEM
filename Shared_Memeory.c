//shared memory program in c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//sender process
void main()
{
   void*sharedMemory;
   char buffer[101];
   //creating shared memory segment
   //it consist key,size and permission
   int shmid=shmget((key_t)111,1024,0666|IPC_CREAT);
    // if(shmid==-1)
    // {
    //     printf("Error in creating shared memory segment");
    // }
    printf("Key of shared memory segment: %d\n",shmid);
    //attaching shared memory segment to process
    //it consist shmid,shared memory address and flag
    sharedMemory=shmat(shmid,NULL,0);

    printf("Process attached at %p\n",sharedMemory);
    printf("Enter some text: ");
    //read from standard input
    read(0,sharedMemory,101);
    //copy the data from shared memory to buffer
    strcpy(buffer,sharedMemory);
    printf("You wrote: %s",buffer);

    printf("----------------");

    // printf("Enter data to be written in shared memory: ");
    // //read from standard input

}

//receiver process
int main()
{
    void *sharedMemory;
    char buffer[101];

    //Getting some id for shared memory segment
    int shmid=shmget((key_t)111,1024,0666);

    printf("Key of shared memory segment: %d\n",shmid);

    //Get the memory location of shared memory segment
    sharedMemory=shmat(shmid,NULL,0);

    printf("Process attached - %p\n",sharedMemory);
    printf("-----------------");

    printf("Data read from shared memory: %s\n",(char*)sharedMemory);
}