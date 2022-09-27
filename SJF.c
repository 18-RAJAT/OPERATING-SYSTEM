#include<stdio.h>
#include<conio.h>

void sjf()
{
    int bt[101],processNo[101],wt[101],tat[101],i,j,n,total=0,position,temp;

    float avgWt,avgTat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("Enter Burst Time: \n");
    for(i=0;i<n;++i)
    {
        printf("Process[%d]: ",i+1);
        scanf("%d",&bt[i]);
        processNo[i]=i+1;
    }

    for(i=0;i<n;++i)
    {
        position=i;
        for(j=i+1;j<n;++j)
        {
            if(bt[j]<bt[position])
            {
                position=j;
           
            }
        }
        temp=bt[i];
        bt[i]=bt[position];
        bt[position]=temp;

        temp=processNo[i];
        processNo[i]=processNo[position];
        processNo[position]=temp;
    }wt[0]=0;
    for(i=1;i<n;++i)
    {
        wt[i]=0;
        for(j=0;j<i;++j)
        wt[i]+=bt[j];
        total+=wt[i];
    }
    avgWt=(float)total/n;total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

    for(i=0;i<n;++i)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
         printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",processNo[i],bt[i],wt[i],tat[i]);
    }

    avgTat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avgWt);
    printf("\nAverage Turnaround Time=%f\n",avgTat);
}

int main()
{
    sjf();
}