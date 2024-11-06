#include<iostream>
using namespace std;

int main()
{
    int p,r;
    p=5;
    r=3;
    
    int alloc[5][3];
    int max[5][3];
    int avail[3];

    cout<<"Enter ther allocation matrix:"<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cout<<"Allocation for P"<<i<<",R"<<j<<":";
            cin>>alloc[i][j];
        }
    }

    cout<<"Enter ther Maximum Demand matrix:"<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cout<<"Max Demand for P"<<i<<",R"<<j<<":";
            cin>>max[i][j];
        }
    }

    cout<<"Enter the available resources:"<<endl;
    for(int j=0;j<r;j++){
        cout<<"Available Unit of R"<<j<<":";
        cin>>avail[j];
    }

    int completed[5]={0};
    int safeSeq[5];
    int index=0;

    int need[5][3];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for(int count=0;count<p;count++){
        
        for(int i=0;i<p;i++){
            if(completed[i]==0)
            {
                bool canProceed=true;

                for(int j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        canProceed=false;
                        break;
                    }
                }
                if(canProceed){
                    safeSeq[index++]=i;
                    for(int j=0;j<r;j++){
                        avail[j]+=alloc[i][j];
                    }
                    completed[i]=1;
                }
            }
        }
    }

    bool isSafe=true;
    for(int i=0;i<p;i++){
        if(completed[i]==0){
            isSafe=false;
            cout<<"The system is not safe"<<endl;
            break;
        }
    }
    if(isSafe)
    {
        cout<<"The Safe Sequence is:"<<endl;
        for(int i=0;i<p-1;i++)
        {
            cout<<"P"<<safeSeq[i]<<"->";
        }
        cout<<"P"<<safeSeq[p-1]<<endl;
    }
    return 0;

}