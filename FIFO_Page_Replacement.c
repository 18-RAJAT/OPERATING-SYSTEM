#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,refStr[10],pageFault=0,frame,page;
    int f,i,j;

    printf("Enter the number of pages: ");
    scanf("%d",&page);

    printf("Enter the reference string: ");
    for(i=0;i<page;++i)
    {
        printf("Value No.[%d]:\t",i+1);
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
        f=0;
        for(j=0;j<frame;++j)
        {
        	if(refStr[i]==temp[j])
        	{
        		f++;
        		pageFault--;
        	}
        }
        pageFault++;
        if((pageFault<=frame)&&(f==0))
        {
        	// int j;
        	temp[i]=refStr[i];
        }
        else if(f==0)
        {
        	// int j;
        	temp[(pageFault-1)%frame]=refStr[i];
        }
        printf("\n");
        for(i=0;i<frame;++i)
        {
        	printf("%d\t",temp[i]);
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pageFault);
}