//Banker Algorithm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int i,j,k,ans[10],need[10][10],alloc[10][10],max[10][10],avail[10],f[10],flag,t,n,m,ind=0;

    printf("Enter the no of Process: ");
    {
        scanf("%d",&n);
    }

    printf("Enter the no of resources: ");
    {
        scanf("%d",&m);
    }
    printf("Avaliable Matrix: ");
    for(i=0;i<m;++i)
    {
        scanf("%d",&avail[i]);
    }

    printf("Allocation Matrix: ");
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Maximum: ");
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            scanf("%d",&max[i][j]);
        }
    }
    for(k=0;k<n;++k)
        f[k]=0;

    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            need[i][j]=max[i][j]-alloc[i][j];

    t=0;
    for(k=0;k<n;++k)
    {
        for(i=0;i<n;++i)
        {
            if(f[i]==0)
            {
                flag=0;
                for(j=0;j<m;++j)
                    if(avail[j]<need[i][j])
                    {
                        flag=1;
                        break;
                    }
                if(flag==0)
                {
                    ans[ind++]=i;
                    for(t=0;t<m;++t)
                        avail[t]+=alloc[i][t];
                    f[i]=1;
                }
            }
        }
    }
    flag=1;
    for(i=0;i<n;++i)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("Not Safe Sequence");
            break;
        }
    }
    if(flag==1)
    {
        printf("Safe Sequence:\n");
        for(i=0;i<n;++i)
        {
            //   printf("P%d ",ans[i]);
            printf("Process%d\n",ans[i]);
        }
        // printf("P%d ",ans[n-1]);
    }
}