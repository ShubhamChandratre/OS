#include<iostream>
using namespace std;

void fifo(int pages[], int n, int capacity)
{
    int frame[capacity];
    int index=0;
    int faults=0;

    for(int i=0;i<capacity;i++){
        frame[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        bool found=false;

        for(int j=0;j<capacity;j++)
        {
            if(frame[i]==pages[i]){
                found=true;
                break;
            }
        }

        if(!found){
            frame[index]=pages[i];
            index=(index+1)%capacity;
            faults++;
        }

        cout<<"Frame: ";
        for(int j=0;j<capacity;j++)
            cout<<frame[j]<<" ";
        cout<<endl;
    }
    cout<<"Total page faults for (FIFO): "<<faults<<endl;;
}

void lru(int pages[],int n,int capacity)
{
    int frame[capacity];
    int time[capacity];
    int faults=0;
    int counter=0;

    for(int i=0;i<capacity;i++)
    {
        frame[i]=-1;
        time[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        bool found=false;
        int least=0;

        for(int j=0;j<capacity;j++)
        {
            if(frame[j]==pages[i])
            {
                found=true;
                time[j]=++counter;
                break;
            }
        }

        if(!found)
        {
            for(int j=0;j<capacity;j++)
            {
                if(time[j]<time[least])
                    least=j;
            }
            frame[least]=pages[i];
            time[least]=++counter;
            faults++;
        }

        cout<<"Frames:";
        for(int j=0;j<capacity;j++)
            cout<<frame[j]<<" ";
        cout<<endl;
    }
    cout<<"Total page faults (LRU):"<<faults<<endl;
}

void optimal(int pages[], int n, int capacity)
{
    int frame[capacity];
    int faults=0;

    for(int i=0;i<capacity;i++){
        frame[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        bool found=false;
        for(int j=0;j<capacity;j++){
            if(frame[j]==pages[i]){
                found=true;
                break;
            }
        }

        if(!found)
        {
            int replace=-1;
            int farthest=i;

            for(int j=0;j<capacity;j++)
            {
                int k;
                for(k=i+1;k<n;k++)
                {
                    if(frame[j]==pages[k]){
                        break;
                    }
                }
                if(k==n){
                    replace=j;
                    break;
                }
                else if(k>farthest){
                    farthest=k;
                    replace=j;
                }
            }

            if(replace==-1)
                replace=0;
            frame[replace]=pages[i];
            faults++;
        }

        cout<<"Frame:";
        for(int j=0;j<capacity;j++){
            cout<<frame[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Total page faults(optimal):"<<faults<<endl;
}

int main()
{
    int choice,n,capacity;
    cout<<"Enter number of pages:";
    cin>>n;
    int pages[n];
    cout<<"Enter the pages:";
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    cout<<"Enter the frame capacity:";
    cin>>capacity;

    do
    {
        cout<<"Select the Page replacement Algorithm:\n1.FIFO\n2.LRU\n3.Optimal\n4.EXIT"<<endl;;
        cin>>choice;

        switch(choice)
        {
            case 1:
                fifo(pages,n,capacity);
                break;
            case 2:
                lru(pages,n,capacity);
                break;
            case 3:
                optimal(pages,n,capacity);
                break;
            case 4:
                cout<<"Exiting Code";
                break;
            default:
                cout<<"Enter valid input";
        }
    }
    while(choice!=4);

    return 0;
}