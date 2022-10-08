#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
// #include<sys/shm.h>

int main()
{
    int i;
    void* shared_memory;
    char buffer[101];
    //creates shared memory segment with key 2345, having size 1024 bytes. IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permissions on the shared segment  
    int shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);  
    
    printf("Key of shared memory is %d ",shmid);
    printf("\n");
    shared_memory=shmat(shmid,NULL,0);
    
    printf("Process attached at %p \n",shared_memory);
    printf("Enter some  data to write to shared memory\n");
    
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("You wrote : %s\n",(char*)shared_memory);
}