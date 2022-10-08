#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,bt[101],wt[101],tat[101],avgWt=0,avgTat=0,i,j;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    
    printf("Enter the burst process\n");
    for(i=0;i<n;++i)
    {
        printf("process[%d]",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    
    for(i=0;i<n;++i)
    {
        wt[i]=0;
        for(int j=0;j<n;++j)
        {
            wt[i]+=bt[i];
        }
    }
    printf("\t\tBT \t\tWT \t\tTAT");
    
    for(i=0;i<n;++i)
    {
        tat[i]=bt[i]+wt[i];
        avgWt+=wt[i];
        avgTat+=tat[i];
        printf("\n\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    avgWt/=i;
    avgTat/=i;
    
    printf("\n\n");
    printf("Waiting time :%d ",avgWt);
    printf("\n\n");
    printf("Turn around time :%d ",avgTat);
}

// int main()
// {
//     int test_case = 1;
//     // cin >> test_case;
//     scanf("%d",&test_case);
//     for (int t = 1; t <= test_case; t++) {
//         // //cout << "Case #" << t << ": ";
//       fcfs();
//     }
// }