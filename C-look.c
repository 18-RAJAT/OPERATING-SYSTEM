#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,cylinder=0,head;
    int i,j;
    int item[20],dist[20];int seekTime=0;

    printf("Enter the locations: \n");
    scanf("%d",&n);

    printf("Head: \n");
    scanf("%d",&head);

    printf("Disk Queue: \n");
    for(i=0;i<n;++i)
    {
    	scanf("%d",&item[i]);
    	dist[i]=(head-item[i]);
    }

    //selection sort algorithm

    for(i=0;i<n-1;++i)
    {
    	for(j=i+1;j<n;++j)
    	{
    		if(dist[i]<dist[j])
    		{
    			int temp=dist[j];
    			dist[j]=dist[i];
    			dist[i]=temp;

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
    printf("J: %d ",j);
    printf("\n\nOrder of disk allocation is as follows:\n");
    for(i=j;i<n;++i)
    {
    	printf(" - : %d",item[i]);
    	cylinder+=abs(head-item[i]);
    	head=item[i];
    }
    for(i=0;i<j;++i)
    {
    	printf(" - : %d",item[i]);
    	cylinder+=abs(head-item[i]);
    	head=item[i];
    }
    printf("\n\nCylinder movement: %d\n\n", cylinder);
}