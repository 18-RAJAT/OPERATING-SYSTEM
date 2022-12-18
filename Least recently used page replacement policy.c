#include<stdio.h>
#include<conio.h>
#include<math.h>

int findLru(int time[],int n)
{
    int minimum=time[0];
    int position=0;

    for(int i=0;i<n;++i)
    {
        if(time[i]<minimum)
        {
            minimum=time[i];
            position=i;
        }
    }
    return position;
}

int main()
{
    int n,noFrame,noPage;
    int frames[10],pages[10],time[10];
    int ct=0,f1,f2,position,pageFault=0;

    printf("Enter the number of frames: ");
    scanf("%d",&noFrame);

    printf("Enter the number of pages: ");
    scanf("%d",&noPage);

    printf("Enter the reference string: ");
    for(int i=0;i<noPage;++i)
    {
        scanf("%d",&pages[i]);
    }

    for(int i=0;i<noFrame;++i)
    {
        frames[i]=-1;
    }
    for(int i=0;i<noPage;++i)
    {
        f1=0;
        f2=0;

        for(int j=0;j<noFrame;++j)
        {
            if(frames[j]==pages[i])
            {
                // f1=1;
                // f2=1;
                ct++;
                time[j]=ct;
                f1=1;
                f2=1;
                break;
            }
        }

        if(f1==0)
        {
            for(int j=0;j<noFrame;++j)
            {
                if(frames[j]==-1)
                {
                    ct++;
                    pageFault++;
                    frames[j]=pages[i];
                    time[j]=ct;
                    f2=1;
                    break;
                }
            }
        }
        if(f2==0)
        {
            //lru call
            position=findLru(time,noFrame);
            // frames[position]=pages[i];
            // time[position]=ct;
            ct++;
            pageFault++;
            frames[position]=pages[i];
            time[position]=ct;
        }
        printf("\n");
        for(int i=0;i<noFrame;++i)
        {
            printf("%d\t",frames[i]);
        }
    }
    printf("Total page fault: %d",pageFault);
}
