#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,n,head=0,item[20],dst[20];
    int limit,cylinders=0;

    printf("Locations: ");
    scanf("%d",&n);

    printf("Head: ");
    scanf("%d",&head);

    printf("Limit: ");
    scanf("%d",&limit);

    printf("Disk Queue: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item[i]);
        dst[i]=(head-item[i]);
    }

    //Selection Sort
    for(i=0;i<n-1;++i)
    {
        for(j=i+1;j<n;++j)
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
    for(i=0;i<n;++i)
    {
        if(item[i]>=head)
        {
            j=i;
            break;
        }
    }
    //disk allocation order
    printf("Order is");
    for(i=j;i<n;++i)
    {
        printf(" -> %d",item[i]);
        cylinders+=abs(head-item[i]);
        head=item[i];
    }
    //change 
    // for(int i=j-1;i>=0;--i)
    for(i=0;i<j;++i)
    {
        printf(" -> %d",item[i]);
        cylinders+=abs(head-item[i]);
        head=item[i];
    }
    printf("\nTotal cylinders: %d",cylinders);
}
