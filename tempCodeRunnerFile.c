/*
SCAN - Disk Scheduling Algorithm (Elevator)
scans down towards the nearest end and then when it hits the bottom,
it scans up servicing the requests that it didn't get going down.
If a request comes in after it has been scanned it will not be serviced
until the process comes back down or moves back up.
*/

#define maxi 100
#define mini 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int queue[1001];
    int head,max,size,sum,temp;
    int locationOfDiskHead;

    printf("Enter the size of queue: ");
    scanf("%d",&size);

    printf("Enter the head position: ");
    scanf("%d",&head);

    printf("Enter the disks\n");
    for(int i=0;i<size;++i)
    {
        scanf("%d",&queue[i]);
    }
    queue[size]=head;
    size++;

    for(int i=0;i<size;++i)
    {
        for(int j=i;j<size;++j)
        {
            if(queue[i]>queue[j])
            {
                //sort the queue
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
    max=queue[size-1];

    //locate head in the queue
    for(int i=0;i<size;++i)
    {
        if(head==queue[i])
        {
            locationOfDiskHead=i;
            break;
        }
    }
    if(abs(head-mini)<=abs(head-maxi))
    {
        for(int i=locationOfDiskHead;i>=0;--i)
        {
            printf("%d -> ",queue[i]);
        }
        // printf("0 -> ");
        for(int j=locationOfDiskHead+1;j<size;++j)
        {
            printf("%d -> ",queue[j]);
        }
    }
    else
    {
        for(int j=locationOfDiskHead+1;j<size;++j)
        {
        	printf("%d -> ",queue[j]);
        }
        for(int j=locationOfDiskHead;j>=0;--j)
        {
        	printf("%d -> ",queue[j]);
        }
    }
    sum=head+max;
    printf("Movement of total cylinders %d",sum);
    return 0;
}