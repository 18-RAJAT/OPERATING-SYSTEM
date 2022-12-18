#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	int n,m,allocated[10][10],maximum[10][10],available[10],need[10][10],f[10],sequence[10];

	int flag;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

	printf("Enter the number of resources: ");
	scanf("%d",&m);

	printf("Enter the allocation matrix: ");
	
	for(int i=0;i<m;++i)
	{
		scanf("%d",&available[i]);
	}


	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			scanf("%d",&maximum[i][j]);
		}
	}
	printf("Enter the available matrix: ");
	for(int k=0;k<n;++k)
	f[k]=0;
	
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	need[i][j]=maximum[i][j]-allocated[i][j];

	int y=0;
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			if(f[i]==0)
			{
				flag=0;
				for(int j=0;j<m;++j)
				{
					if(need[i][j]>available[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					sequence[y++]=i;
					for(int j=0;j<m;++j)
					available[j]+=allocated[i][j];
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
			printf("The system is not in safe state");
			break;
		}
	}
	if(flag==1)
	{
		printf("The system is in safe state and the safe sequence is: ");
		for(int i=0;i<n;++i)
		{
			printf("%d ",sequence[i]);
		}
	}
	return 0;
}