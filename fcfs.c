// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>

// int main()
// {
//     int n,bt[101],wt[101],tat[101],avgWt=0,avgTat=0,i,j;
//     printf("Enter the number of process: ");
//     scanf("%d",&n);
    
//     printf("Enter the burst process\n");
//     for(i=0;i<n;++i)
//     {
//         printf("process[%d]",i+1);
//         scanf("%d",&bt[i]);
//     }
//     wt[0]=0;
    
//     for(i=0;i<n;++i)
//     {
//         wt[i]=0;
//         for(int j=0;j<n;++j)
//         {
//             wt[i]+=bt[i];
//         }
//     }
//     printf("\t\tBT \t\tWT \t\tTAT");
    
//     for(i=0;i<n;++i)
//     {
//         tat[i]=bt[i]+wt[i];
//         avgWt+=wt[i];
//         avgTat+=tat[i];
//         printf("\n\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
//     }
//     avgWt/=i;
//     avgTat/=i;
    
//     printf("\n\n");
//     printf("Waiting time :%d ",avgWt);
//     printf("\n\n");
//     printf("Turn around time :%d ",avgTat);
// }

// // int main()
// // {
// //     int test_case = 1;
// //     // cin >> test_case;
// //     scanf("%d",&test_case);
// //     for (int t = 1; t <= test_case; t++) {
// //         // //cout << "Case #" << t << ": ";
// //       fcfs();
// //     }
// // }




#include<stdio.h>

int main(){

	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;

	printf("Enter number of processes	");
	scanf("%d",&n);

	printf("Enter arrival time and burst time for each process\n\n");

	for(int i=0;i<n;i++)
	{

		printf("Arrival time of process[%d]	",i+1);
		scanf("%d",&at[i]);
		
		printf("Burst time of process[%d]	",i+1);
		scanf("%d",&bt[i]);
		
		printf("\n");
	}
		
	//calculate completion time of processes 	

	for(int j=0;j<n;j++)
	{
		sum+=bt[j];
		ct[j]+=sum;
	}

	//calculate turnaround time and waiting times 

	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}

	
	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}
	
	printf("Solution: \n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	
	for(int i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	
	return 0;
}
