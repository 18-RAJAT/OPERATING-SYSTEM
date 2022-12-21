#include<stdio.h>
#include<stdlib.h>
int main()
{    
    int p[101],bt[101],wt[101],tat[101],pr[101],i,j,n,total=0,pos,temp;
    float avgWt,avgTat;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter burst time and priority");
    for(i=0;i<n;++i)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;//process num
    }
    for(i=0;i<n;++i)
    {
        pos=i;
        for(j=i+1;j<n;++j)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

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
    avgWt=(float)total/n;
    total=0;
    printf("\nProcess\t    Burst Time\t    Waiting Time\tTurnaround Time");
    for(i=0;i<n;++i)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avgTat=(float)total/n;

    printf("\n\nAverage Waiting Time=%f",avgWt);
    printf("\nAverage Turnaround Time=%f",avgTat);
    
    return 0; 
}