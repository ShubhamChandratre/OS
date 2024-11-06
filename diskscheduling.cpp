#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void sort(int request[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(request[j+1]<request[j])
            {
                int temp =request[j+1];
                request[j+1]=request[j];
                request[j]=temp;
            }
        }
    }
}

int closest(int request[],bool visited[],int head,int n)
{
    int min=99999;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int dist=abs(head-request[i]);
            if(dist<min)
            {
                min=dist;
                index=i;
            }
        }
    }
    return index;
}

void sstf(int request[],int n,int head)
{
    printf("%d\n",head);
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    sort(request,n);
    int totalseek=0;
    for(int i=0;i<n;i++)
    {
        int minindex=closest(request,visited,head,n);
        totalseek+=abs(head-request[minindex]);
        visited[minindex]=true;
        head=request[minindex];
        printf("%d\n",head);

    }
    printf("%d",totalseek);
}

void scan(int request[],int n,int head,int direction,int size)
{
    int total=0;
    sort(request,n);
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(request[i]>head)
        {
            index=i;
            break;
        }
    }
    if(direction==1)
    {
        for(int i=index;i<n;i++)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }
        if(head!=size-1)
        {
            total+=abs(head-size-1);
            head=size-1;
        }
        for(int i=index-1;i>=0;i--)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }
    }
    else
    {
        for(int i=index-1;i>=0;i--)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }
        if(head!=0)
        {
            total+=abs(head-0);
            head=0;
        }
        for(int i=index;i<n;i++)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }

    }
    printf("%d",total);
}

void clook(int request[],int n,int head,int direction,int size)
{
    int total=0;
    sort(request,n);
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(request[i]>head)
        {
            index=i;
            break;
        }
    }
    if(direction==1)
    {
        for(int i=index;i<n;i++)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }
        
        for(int i=0;i<index;i++)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }
    }
    else
    {
        for(int i=index-1;i>=0;i--)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }
        for(int i=n-1;i>=index;i--)
        {
            total+=abs(head-request[i]);
            head=request[i];
        }

    }
    printf("%d",total);
}

int main()
{
    int n;
    printf("Enter number of seeks");
    scanf("%d",&n);
    int request[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter seek");
        scanf("%d",&request[i]);
    }
    int head;
    printf("Enter head");
    scanf("%d",&head);
    int size;
    printf("size");
    scanf("%d",&size);

    sstf(request,n,head);
    printf("\n");
    scan(request,n,head,0,size);
    printf("\n");
    clook(request,n,head,0,size);
    printf("\n");
    
    return 0;
}