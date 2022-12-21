//preemtive priority scheduling

#include<stdio.h>
#include<conio.h>

int main()
{
	int p[20],bt[10],wt[10],tat[10],pr[10],pos,temp,total=0,i,j,n;
	
	float awt,atat;
	printf("Process:");scanf("%d",&n);
	printf("Enter the burst time and priority");
	for(i=0;i<n;++i)
	{
		printf("Enter the burst time :");
		scanf("%d",&bt[i]);
		
		printf("Enter the priority :");
		scanf("%d",&pr[i]);
		
		p[i]=i+1;		
	}
	for(i=0;i<n;++i)
	{
		//ith value
		pos=i;
		for(j=i+1;j<n;++j)
		{
			if(pr[j]<pr[pos])
			{
				//if greater pos<-j;
				pos=j;
			}
		}
		temp=pr[i];
		pr[i]=bt[pos];
		bt[pos]=temp;
		
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	
	
	
	for(i=1;i<n;++i)
	{
		wt[i]=0;
		for(j=0;j<i;++j)
		wt[i]+=bt[j];
		total+=wt[i];
	}
	awt=total/n;
		
	total=0;
	printf("\nProcess\t    Burst Time\t    Waiting Time\tTurnaround Time");
	for(i=0;i<n;++i)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	atat=total/n;
	printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f",atat);
}












