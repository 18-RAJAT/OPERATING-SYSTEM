#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int n,at[n],bt[n],remBt[n],sq=0;
	int timeQuantum;
	printf("Enter the number of process: ");
	scanf("%d",&n);

	printf("Arrival Time: ");
	for(int i=0;i<n;++i)
	{
		printf("at[%d] : ",i+1);
		scanf("%d",&at[i]);
	}

	printf("Burst Time: ");
	for(int i=0;i<n;++i)
	{
		printf("bt[%d] : ",i+1);
		scanf("%d",&bt[i]);
		remBt[i]=bt[i];
	}
	printf("Time Quantum: ");
	scanf("%d",&timeQuantum);
	int store=n;
	int temp;
	int ct=0;
	int total=0;

	float awt,atat;
	
	printf("Ans:\n");
	printf("Process\t\tBurst Time\t\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");

	for(int i=0,total=0;store!=0;)
	{
		if(remBt[i]<=timeQuantum && remBt[i]>0)
		{
			ct+=remBt[i];
			remBt[i]=0;
			sq=1;
		}
		else if(remBt[i]>0)
		{
			remBt[i]-=timeQuantum;
			ct+=timeQuantum;
		}
		if(remBt[i]==0 && sq==1)
		{
			store--;
			printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],ct,ct-at[i],ct-at[i]-bt[i]);
			total+=ct-at[i]-bt[i];
			sq=0;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(at[i+1]<=ct)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	atat=(float)total/n;
	printf("Average Turnaround Time: %f ",atat);
	// return 0;

	awt=(float)total/n;
	printf("Average Waiting Time: %f ",awt);
	return 0;
}