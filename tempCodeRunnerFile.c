#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,refStr[20],pageFault=0,frame,page;
    int f,i,j;

    printf("Enter the number of pages: ");
    scanf("%d",&page);

    printf("Enter the reference string: ");
    for(i=0;i<page;++i)
    {
        printf("Value No.[%d]:\n",i+1);
        scanf("%d",&refStr[i]);
    }
    printf("Enter the frame: ");
    {
        scanf("%d",&frame);
    }

    int temp[frame];
    for(i=0;i<frame;++i)
    {
        temp[i]=-1;
    }

    for(i=0;i<page;++i)
    {
        f=1;
        for(j=0;j<frame;++j)
        {
            if(temp[j]==refStr[i])
            {
                f=0;
                break;
            }
        }
        if(f==1)
        {
            for(j=0;j<frame-1;++j)
            {
                temp[j]=temp[j+1];
            }
            temp[j]=refStr[i];
            pageFault++;
        }
    }
    // for(i=0;i<frame;++i)
    // {
    //     printf("%d\n\t",temp[i]);
    // }
    printf("Page Fault: %d",pageFault);
    return 0;

}