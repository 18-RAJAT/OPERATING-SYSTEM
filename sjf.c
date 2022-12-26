#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int bt[101],process[101],ct[101],wt[101],tat[101],total=0,n,pos,temp;
    float avgWt,avgTat;
    
    printf("Enter the number of process\n");
    scanf("%d",&n);
    
    printf("Enter the burst time \n");
    for(int i=0;i<n;++i)
    {
        printf("process[%d]",i+1);
        scanf("%d",&bt[i]);
        process[i]=i+1;
    }

    //sorting the bt
    for(int j=0;j<n;j++)
	{
		total+=bt[j];
		ct[j]+=total;
	}

    for(int i=0;i<n;++i)
    {
        pos=i;
        for(int j=i+1;j<n;++j)
        {
            if(bt[j]<bt[pos])
            {
                pos=j;
            }
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    wt[0]=0;
    for(int i=0;i<n;++i)
    {
        wt[i]=0;
        for(int j=0;j<i;++j)
        wt[i]+=bt[j];
        total+=wt[i];
    }
    avgWt=(float)total/n;
    total=0;
    printf("\nProcess\t    Burst Time\t    completion time \tWaiting Time\tTurnaround Time");
    
    for(int i=0;i<n;++i)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        
        printf("\np%d\t\t  %d\t\t  %d\t\t  %d\t\t\t%d",process[i],bt[i],wt[i],tat[i]);
    }
    avgTat=(float)total/n;
    printf("\n");
    printf("Avg wt time=%f",avgWt);
    printf("\n");
    printf("Avg tat time=%f",avgTat);
}



// #include<stdio.h>

// int main(){

// 	int n,tat[20], wt[20], bt[20],P[20],i,j, pos=-1, avgwt=0, avgtat=0;
// 	printf("Enter no. of processes (max 20) : ");
// 	scanf("%d",&n);

// 	//Input CPU burst time for all processes
// 	for(i=0;i<n;i++)
// 	{
// 		printf("P[%d]:",i);
// 		scanf("%d", &bt[i]);
// 		P[i]=i+1;
// 	}

// 	//Sort CPU burst time in ascending order using selection sort
// 	for(i=0;i<n;i++)
// 	{
// 		pos=i;
// 		for(j=i+1;j<n;j++)
// 		{
// 			if(bt[j]<bt[i])
// 				pos=j;
// 		}
// 		int temp=P[i];
// 		P[i]=P[pos];
// 		P[pos]=temp;

// 		temp=bt[i];
// 		bt[i]=bt[pos];
// 		bt[pos]=temp;
// 	}

// 	printf("Printing sorted array:");
// 	for(i=0;i<n;i++)
// 		printf(" %d --> %d",P[i],bt[i]);
	
// 	//Calculating waiting time
// 	wt[0]=0;
// 	for(i=1;i<n;i++)
// 	{
// 		wt[i]=0;
// 		for(j=0;j<i;j++)
// 			wt[i]+=bt[j];
// 		avgwt+=wt[i];
// 	}
// 	avgwt/=n;
// 	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
// 	for(i=0;i<n;i++)
//     	{
// 		tat[i]=bt[i]+wt[i];     //calculate turnaround time
// 	        avgtat+=tat[i];
// 	        printf("\np[%d]\t\t  %d\t\t    %d\t\t\t%d",P[i],bt[i],wt[i],tat[i]);
    	
// 	}

// 	avgtat/=n;
// 	printf("\nAverage waiting time: %d", avgwt);
// 	printf("\nAverage turn around time: %d\n\n", avgtat);
	


// 	return 0;
// }