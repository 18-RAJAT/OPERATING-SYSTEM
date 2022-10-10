#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,i,total=0,x,counter=0,timeQuantum,wt=0,tat=0,at[101],bt[101],temp[101];
    float avgWt,avgTat;
    
    printf("Enter the process: ");
    scanf("%d",&n);
    x=n;
    for(i=0;i<n;++i)
    {
	    printf("Enter arrival time: ");
	    scanf("%d",&at[i]);
	    
	    printf("Enter the burst time: ");
	    scanf("%d",&bt[i]);
	    
	    temp[i]=bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d",&timeQuantum);
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    
    for(total=0;i=0;x!=0)
    {
    	if(temp[i]<=timeQuantum && temp[i]>0)
    	{
    		total+=temp[i];
    		temp[i]=0;
    		counter=1;
    	}
    	else if(temp[i]>0)
    	{
    		temp[i]-=timeQuantum;
    		total+=timeQuantum;
    	}
    	if(temp[i]==0 && counter==1)
    	{
    		x--;
    		printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
    		wt+=total-at[i]-bt[i];
    		tat+=total-at[i];
    		counter=0;
    	}
    	if(i==n-1)
    	{
    		i=0;
    	}
    	else if(at[i+1]<=n)
    	{
    		i++;
    	}
    	else
    	{
    		i=0;
    	}
    }
    avgWt=wt*1.0/n;
    avgTat=tat*1.0/n;
    
    printf("avg waiting time: %f",avgWt);
    printf("\n");
    printf("avg turn around time: %f",avgTat);
}