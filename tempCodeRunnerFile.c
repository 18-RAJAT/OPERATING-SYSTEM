#include<stdio.h>
#include<conio.h>

void fcfs()
{
    int n,bt[1001],wt[1001],tat[1001],avgWt=0,avgTat=0;
    int i,j;
    printf("Enter the number of processes :");
    scanf("%d",&n);

    printf("Enter the process of burst time :");
    for(i=0;i<n;++i)
    {
        printf("\nP[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    //first process
    wt[0]=0;

    //waiting time 
    for(i=1;i<n;++i)
    {
        wt[i]=0;
        for(j=0;j<i;++j)
        {
            wt[i]+=bt[j];
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

        //calculate turnaround time
        for(i=0;i<n;++i)
        {
            tat[i]=wt[i]+bt[i];
            avgWt+=wt[i];
            avgTat+=tat[i];
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        }
        avgTat/=i;
        avgWt/=i;
        printf("\nAverage Waiting Time : %d",avgWt);
        printf("\n\nAverage Turnaround Time : %d",avgTat);
    }
}

int main()
{
    fcfs();
    return 0;
}