#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
    int queue1[20],queue2[20],queue3[20],seek=0;
    int max,diff,head,n,m,temp1=0,temp2=0;
    int i,j;
    
    float avg;
    
    printf("Enter the max range of the disk:\n ");
    scanf("%d",&max);
    
    printf("Enter the initial head position:\n ");
    scanf("%d",&head);
    
    printf("Enter the size of queue requests:\n ");
    scanf("%d",&n);
    
    printf("Enter the queue of disk positions:\n ");
    for(i=1;i<=n;++i)
    {
    	scanf("%d",&m);
    	{
    		if(m>=head)
    		{
    			queue2[temp1]=m;
    			temp1++;
    		}
    		else
    		{
    			queue3[temp2]=m;
    			temp2++;
    		}
    	}
    }
    	//
    	for(i=0;i<temp1-1;++i)
    	{
    		for(j=i+1;j<temp1;++j)
    		{
    			if(queue2[i]>queue2[j])
    			{
    				//sort
    				m=queue2[i];
    				queue2[i]=queue2[j];
    				queue2[j]=m;
    			}
    		}
    	}
    	//
    	for(i=0;i<temp2-1;++i)
    	{
    		for(j=i+1;j<temp2;++j)
    		{
    			if(queue3[i]<queue3[j])
    			{
    				//sort
    				m=queue3[i];
    				queue3[i]=queue3[j];
    				queue3[j]=m;
    			}
    		}
    	}
        // for(i=1,j=0;j<temp1;++i,++j)
        for(int i=1,j=0;j<temp1;++i,++j)
        {
            // for(int j=0;j<temp1;++j)
            for(int j=0;j<temp1;++j)
            {
                queue1[i]=queue2[j];
            }
        }
        queue1[i]=max;
        queue1[i+1]=0;
    	
        // for(i=temp1+3,j=0;j<temp2;++i,++j)
        for(int i=temp1+3;j<temp2;++i,++j)
        {
            // for(int j=0;j<temp2;++j)
            for(int j=0;j<temp2;++j)
            {
                queue1[i]=queue3[j];
            }
        }
        queue1[0]=head;
    	for(j=0;j<=n+1;++j)
    	{
    		diff=abs(queue1[j+1]-queue1[j]);
    		seek+=diff;
    		
    		printf("Disk head moves from %d to %d with seek %d\n",queue1[j],queue1[j+1],diff);
    	}
    	
    	printf("Total seek time %d\n",seek);
    	
    	avg=seek/n;
    	printf("Avg seek time is %f\n",avg);
}
// Input: I/O requests - { 19, 80, 134, 11, 110, 23, 162, 64 }

// Initial head position - 50
