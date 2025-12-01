#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of process"<<endl;
    cin>>n;

    int at[n];
    int bt[n];
    int ft[n];
    int wt[n];
    int tat[n];
    int c[n]={0};
    int p[n];
    int rt[n];

    for(int i =0;i<n;i++){
        cout<<"enter arrival time of process "<<i+1<<":";
        cin>>at[i];
        cout<<"enter burst time of process"<<i+1<<":";
        cin>>bt[i];
        rt[i]=bt[i];
        cout<<"enter priority of process"<<i+1<<":";
        cin>>p[i];
    }
    int ct =0;
    int done =0;
    while(done!=n){
        int index = -1;
        int priority = -1e9;
        for(int i =0;i<n;i++){
            if(c[i]!=1 && at[i]<=ct){
                if(p[i]>priority){
                    priority=p[i];
                    index =i;
                }
            }
        }

        if(index==-1){
            ct++;
            continue;
        }

        ct++;
        rt[index]--;

        if(rt[index]==0){
            ft[index] = ct;
            tat[index] = ft[index]-at[index];
            wt[index] = tat[index]-bt[index];
            done++;
            c[index]=1;
        }
    }

    cout << "\nProcess\tAT\tBT\tP\tFT\tTAT\tWT\n";
    for(int i = 0; i < n; i++){
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<p[i]
            <<"\t"<<ft[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
    return 0;
}
