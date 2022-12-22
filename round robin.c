#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,qt,count=0,temp,f=0,bt[101],wt[101],tat[101],rt[101],ct[101];
	float avgWt=0,avgTat=0;

	printf("Enter number of process: ");
	scanf("%d",&n);

	printf("Enter the burst time\n");
	for(i=0;i<n;++i)
	{
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("Time quantum: ");
	scanf("%d",&qt);


	while(1)
	{
		for(i=0,count=0;i<n;++i)
		{
			temp=qt;
			if(rt[i]==0)
			{
				count++;
				continue;
			}
			if(rt[i]>qt)
			{
				rt[i]-=qt;
			}
			else
				if(rt[i]>=0)
				{
					temp=rt[i];
					rt[i]=0;
				}
			f+=temp;
			tat[i]=f;
		}
		if(n==count)
		{
			break;
		}
	}
	printf("\nprocess\t\tBurst time\t\tTurnaround time\t\tWaiting time");

	for(i=0;i<n;++i)
	{
		wt[i]=tat[i]-bt[i];
		avgWt+=wt[i];
		avgTat+=tat[i];
		printf("\n%d\t\t%d\t\t\t\t%d\t\t\t%d",i+1,bt[i],tat[i],wt[i]);
	}
	avgWt/=n;
	avgTat/=n;
	printf("\nAverage waiting time=%f",avgWt);
	printf("\nAverage turnaround time=%f",avgTat);
}
// Enter number of process: 3
// Enter the burst time
// 10
// 5
// 8
// Time quantum: 2

// process         Burst time              Turnaround time         Waiting time
// 1               10                              23                      13
// 2               5                               15                      10
// 3               8                               21                      13
// Average waiting time=12.000000
// Average turnaround time=19.666666