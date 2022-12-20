#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

int main()
{
    //pipefds[0] is for reading
    //pipefds[1] is for writing
    int pipefds[2];

    if(pipe(pipefds)==-1)
    {
    	printf("Error");
    	return 0;
    }
    int id=fork();
    //child process will write to pipe
    if(id==0)
    {
        //close reading end
        close(pipefds[0]);
        
        int a;
        printf("Enter the number: ");
        scanf("%d",&a);

        //write to pipe
    
        //writing in variable a to pipefds[1]
        write(pipefds[1],&a,sizeof(a));

        //close writing end of pipe
        close(pipefds[1]);
    }
    else
    {
        //closing writing end of pipe as parent process will read from pipe
        close(pipefds[1]);

        int b;
        //reading from pipefds[0] to variable b
        read(pipefds[0],&b,sizeof(b));

        //close reading end of pipe
        // close(pipefds[0]);
        printf("The value passed from child process is: %d: ",b);

        //close reading end of pipe
        close(pipefds[0]);
    }
}