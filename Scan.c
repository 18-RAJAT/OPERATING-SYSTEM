#include<stdio.h>
#include<stdlib.h>

void swap(int disk[],int i,int j){
    int temp=disk[i];
    disk[i]=disk[j];
    disk[j]=temp;
}

int main(){
    int tracks,totaltracks;
    printf("Enter total tracks\n");
    scanf("%d",&totaltracks);
    
    printf("Enter the number tracks on disk\n");
    scanf("%d",&tracks);
    
    int disk[tracks];
    printf("Enter the tracks\n");
    for(int i=0;i<tracks;i++){
        scanf("%d",&disk[i]);
    }
    
    int head,start=-1;
    printf("Enter the head of Read/Write head\n");
    scanf("%d",&head);
    
    
    //sorting
    for(int i=0;i<tracks;i++){
        int mn=disk[i];
        int ind=i;
        for(int j=i+1;j<tracks;j++){
            if(disk[j]<mn){
                mn=disk[j];
                ind=j;
            }
        }
        swap(disk,i,ind);
        if(disk[i]>=head && start<0)start=i-1;
    }
    
    for(int i=start;i<tracks;i++){ //going forward only first
        printf("%d ",disk[i]);
    }
    for(int i=start-1;i>=0;i--){ // going backward only later
        printf("%d ",disk[i]);
    }
    printf("\nTotal tracks movement - %d\n",(totaltracks-head)+(totaltracks-disk[0]));
}