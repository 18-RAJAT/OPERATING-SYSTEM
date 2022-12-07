#include<stdio.h>
#include<stdlib.h>

#define low 0
#define high 1001

void scanDiskScheduling()
{
    int queue[1001];
    int head,maximum,q_size,temp,sum,locationOfDiskHead;

    // for(int i=0;i<1001;i++)
    //     queue[i]=0;

    printf("Enter the no of disk locations: ");
    scanf("%d",&q_size);

    printf("Enter the head position: ");
    scanf("%d",&head);

    // for(int i=0;i<q_size;++i)
    printf("Enter the disk queues: ");// 1,2,5,6,9,11
    for(int i=0;i<q_size;++i)
        scanf("%d",&queue[i]);

    queue[q_size]=head;
    q_size++;

    sort the queue
    for(int i=0;i<q_size;++i)
    {
        for(int j=i+1;j<q_size;++j)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }

}