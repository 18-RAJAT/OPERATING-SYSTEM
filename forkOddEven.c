#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
/* FUNCTIONS */
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(i,s,e) for(long long int i=s;i>=e;--i)
#define For1(i,n) or(long long int i=0;i<n+1;++i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FO(i,s,e) for(long long int i=1;i*i<=y;i++)
#define rf(i,e,s) for(long long int i=n;i>=0;--i)
#define pass(a)  for(long long int i=n-1;i>=1;i-=2)


int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int pid=fork();
    if(pid==0)
    {
        f1(i,0,10)
        {
            if(a[i]%2==0)
            {
                printf("parent: %d ",a[i]);
            }
        }
    }
    else if(pid>0)
    {
        f1(i,0,10)
        {
            if(a[i]%2!=0)
            {
                printf("child: %d ",a[i]);
            }
        }
    }
}