// #include<stdio.h>
// #include<stdlib.h>

// void swap(int disk[],int i,int j){
//     int temp=disk[i];
//     disk[i]=disk[j];
//     disk[j]=temp;
// }

// int main(){
//     int tracks,totaltracks;
//     printf("Enter total tracks\n");
//     scanf("%d",&totaltracks);
    
//     printf("Enter the number tracks on disk\n");
//     scanf("%d",&tracks);
    
//     int disk[tracks];
//     printf("Enter the tracks\n");
//     for(int i=0;i<tracks;i++){
//         scanf("%d",&disk[i]);
//     }
    
//     int head,start=-1;
//     printf("Enter the head of Read/Write head\n");
//     scanf("%d",&head);
    
    
//     //sorting
//     for(int i=0;i<tracks;i++){
//         int mn=disk[i];
//         int ind=i;
//         for(int j=i+1;j<tracks;j++){
//             if(disk[j]<mn){
//                 mn=disk[j];
//                 ind=j;
//             }
//         }
//         swap(disk,i,ind);
//         if(disk[i]>=head && start<0)start=i-1;
//     }
    
//     for(int i=start;i<tracks;i++){ //going forward only first
//         printf("%d ",disk[i]);
//     }
//     for(int i=start-1;i>=0;i--){ // going backward only later
//         printf("%d ",disk[i]);
//     }
//     printf("\nTotal tracks movement - %d\n",(totaltracks-head)+(totaltracks-disk[0]));
// }


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, head, item[20], dst[20], limit;
    int cylinders=0;
    printf("Enter no. of locations:");
    scanf("%d",&n);
    printf("Enter position of head:");
    scanf("%d",&head);
    printf("Enter cylinder limit:");
    scanf("%d",&limit);

    printf("Enter elements of disk queue:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item[i]);
        dst[i]=(head-item[i]);
    }
    //Selection Sort
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(dst[j]>dst[i])
            {
                int temp=dst[j];
                dst[j]=dst[i];
                dst[i]=temp;

                temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(item[i]>=head)
        {
            j=i;
            break;
        }
    }

    printf("j=%d", j);
    printf("\n\nOrder of disk allocation is as follows:\n");
    for(i=j;i<n;i++)
    {
        printf(" -> %d", item[i]);
        cylinders+= abs(head-item[i]);
        head=item[i];

    }

    //change
    cylinders+= abs(limit-head) + limit ;
    head =0;
    for(i=j-1;i>=0;i--)
    {
        printf(" -> %d", item[i]);
        cylinders+= abs(head-item[i]);
        head=item[i];

    }

    printf("\n\nCylinder movement: %d\n\n", cylinders );
}