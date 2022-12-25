#include<stdio.h>

int main()
{
    int nFrame,n,frames[30],pages[30],cnt=0,time[30],flag1,flag2,i,j,pos,pageFault=0;
    printf("Enter number of frames: ");
    scanf("%d",&nFrame);

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page numbers: ");

    for(i=0;i<n;++i)
        scanf("%d",&pages[i]);

    for(i=0;i<nFrame;++i)
        frames[i]=-1;

    for(i=0;i<n;++i)
    {
        flag1=flag2=0;

        for(j=0;j<nFrame;++j)
        {
            if(pages[i]==frames[j])
            {
                cnt++;
                time[j]=cnt;
                flag1=flag2=1;
                break;
            }
        }

        if(flag1==0)
        {
            for(j=0;j<nFrame;++j)
            {
                if(frames[j]==-1)
                {
                    cnt++;
                    pageFault++;
                    frames[j]=pages[i];
                    time[j]=cnt;
                    flag2=1;
                    break;
                }
            }
        }

        if(flag2==0)
        {
            pos=0;
            for(j=1;j<nFrame;++j)
            {
                if(time[j]<time[pos])
                    pos=j;
            }

            cnt++;
            pageFault++;
            frames[pos]=pages[i];
            time[pos]=cnt;
        }

        printf("\n");

        for(j=0;j<nFrame;++j)
            printf("%d\t",frames[j]);
    }

    printf("\n\nTotal Page Faults = %d",pageFault);
    printf("\nMiss Ratio = %f",(pageFault/(1.0*n)));
    printf("\nHit Ratio = %f",1-(pageFault/(1.0*n)));

    return 0;
}