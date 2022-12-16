#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j;
    int n,a[1001],frames[1001],noOfFrames,k,avail,ct=0;

    printf("Enter the number of pages: ");
    scanf("%d",&n);

    printf("Enter the page numbers: ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    printf("Enter the number of frames: ");
    scanf("%d",&noOfFrames);

    for(i=0;i<noOfFrames;i++)
        frames[i]=-1;
        j=0;
        printf("string \t page frames\n");
    for(i=1;i<=n;++i)
    {
        printf("%d\t\t",a[i]);
        avail=0;

        for(k=0;k<noOfFrames;++k)
            if(frames[k]==a[i])
                avail=1;

        if(avail==0)
        {
            frames[j]=a[i];
            j=(j+1)%noOfFrames;
            ct++;

            for(k=0;k<noOfFrames;++k)
                printf("%d\t",frames[k]);
        }
        printf("\n");
    }
    printf("Page Fault is %d",ct);
    return 0;
}