#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int at[10],bt[10],rt[10],et,i,smallest;
    int remain=0,n,time,wt=0,tat=0;

    printf("Enter no of processes : ");
    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        printf("Arrival time process process[%d] : ",i+1);
        scanf("%d",&at[i]);

        printf("Burst time process[%d] : ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
    rt[9]=9999;
    for(time=0;remain!=n;time++)
    {
        smallest=9;

        for(int i=0;i<n;++i)
        {
            if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            et=time+1;
            printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,et-at[smallest],et-at[smallest]-bt[smallest]);

            wt+=et-bt[smallest]-at[smallest];
            tat+=et-at[smallest];
        }
    }
    printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
    printf("Avg Turnaround Time = %f",tat*1.0/n);
}