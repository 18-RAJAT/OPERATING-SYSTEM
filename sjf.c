#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int bt[101],process[101],wt[101],tat[101],total=0,n,pos,temp;
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
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    
    for(int i=0;i<n;++i)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],bt[i],wt[i],tat[i]);
    }
    avgTat=(float)total/n;
    printf("\n");
    printf("Avg wt time=%f",avgWt);
    printf("\n");
    printf("Avg tat time=%f",avgTat);
}