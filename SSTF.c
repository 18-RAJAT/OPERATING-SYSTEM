#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,i,j,min,head,item[20],dst[20];
    int cylinders=0;
    printf("Locations: ");
    scanf("%d",&n);

    printf("Head: ");
    scanf("%d",&head);
    
    printf("Disk Queue: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item[i]);
        // dst[i]=(head-item[i]);
    }
    //Selection Sort
    int ct=n;
    // printf("order of disk is as follows:\n");
    while(ct>0)
    {
        // printf("Distance Array");
        for(i=0;i<n;++i)
        {
            if(item[i]==-1)continue;

            dst[i]=abs(head-item[i]);
            // min=i;
            // break;
            printf("%d ",dst[i]);
        }
        //selection sort 
        for(i=0;i<n;++i)
        {
            if(item[i]!=-1)
            {
                min=i;
                break;
                // continue;
            }
        }
        for(i=1;i<n;++i)
        {
            if(item[i]==-1)continue;

            if(dst[min]>dst[i])min=i;
        }
        // printf("Minimum : %d",min);
        cylinders+=dst[min];
        // printf(" -> %d",item[min]);
        head=item[min];
        item[min]=-1;
        ct--;
    }
    printf("\n\n");
    printf("Cylinder movement: %d \t", cylinders );
}