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
    int pid=fork();
    
    int n;printf("%d Enter the number",n);
    scanf("%d",&n);
    
    if(pid>0){printf("Parent process work:");}
    // {sleep(20);}
    else if(pid==0){sleep(20);printf("Child process work:");}
    else{printf("Error");}
    // else {exit(0);}
}