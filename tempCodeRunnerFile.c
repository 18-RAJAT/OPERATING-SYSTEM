#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int need[10][10],ans[10],index=0,x,y,flag,f[10];
	int n,m,alloc[10][10],max[10][10],avail[10];

	printf("Enter the number of process: \n");
	scanf("%d",&n);
	
	printf("Enter the number of resources: \n");
	scanf("%d",&m);
	
	printf("Enter the available resource matrix: \n");
	for(int i=0;i<m;++i)
	scanf("%d",&avail[i]);
	
	printf("Enter the allocation matrix: ");
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&alloc[i][j]);
	printf("Enter the max matrix: ");
	for(int i=0;i<n;++i)
	for(int j=0;i<m;++j)
	
	scanf("%d",&max[i][j]);
	
	for(int k=0;k<n;++k)
	f[k]=0;
	
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	
	need[i][j]=max[i][j]-alloc[i][j];
	
	y=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(f[j]==0)
			{
				flag=0;
				
				for(int k=0;k<m;++k)
				{
					if(need[j][k]>avail[k])
					{
						flag=1;
						break;
					}
					if(flag==0)
					{
						ans[index++]=i;
						for(int x=0;x<m;++x)
						{
							avail[x]+=alloc[j][x];
							f[i]=1;
						}
					}
				}
			}
			flag=1;
			for(int i=0;i<n;++i)
			{
				if(f[i]==0)
				{
					flag=0;
					printf("Not Sequenced: ");
				}
			}
			if(flag==1)
			{
				printf("Safe Sequence: ");
				for(int i=0;i<n;++i)
				{
					printf("%d\t: "ans[i]);
				}
			}
		}
	}
	
}