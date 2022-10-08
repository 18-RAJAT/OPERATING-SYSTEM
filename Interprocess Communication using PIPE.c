#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pipefds[2];

    if(pipe(pipefds)==1)
    {
        //error
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    printf("Read file value: %d\n",pipefds[0]);
    printf("Write file value: %d\n",pipefds[1]);

    return EXIT_SUCCESS;
}