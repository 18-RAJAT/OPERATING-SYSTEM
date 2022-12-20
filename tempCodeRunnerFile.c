/*
	Disk Scheduling
	First Come First Serve
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int noOfRequests,head;
	printf("Enter the number of requests:= ");
	scanf("%d",&noOfRequests);
	
	printf("Enter the number of requests:\n");
	int req[noOfRequests];
	for(int i=0;i<noOfRequests;++i)
	{
		scanf("%d",&req[i]);
	}
	
	printf("Enter the initial position of R/W head:= ");
	scanf("%d",&head);
	
	int seekTime=0;
	printf("%d: ",head);
	for(int i=0;i<noOfRequests;++i)
	{
		if(i==noOfRequests-1)
		{
			printf("%d\n",req[i]);
		}
		else
		{
			printf("%d---: ",req[i]);
		}
		seekTime+=abs(req[i]-head);
		head=req[i];
	}
	printf("Seek time: %d\n",seekTime);
}

//sample input->n=7->82,170,43,140,24,16,190->initial head=50 answer=642