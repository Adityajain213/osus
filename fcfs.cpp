#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of process: ";
    cin>>n;
     
    int at[n];
    int wt[n];
    int ft[n];
    int tat[n];
    int bt[n];

    for(int i =0;i<n;i++){
        cout<<"enter arrival time of process "<<i+1<<":";
        cin>>at[i];

        cout<<"enter burst time of process "<<i+1<<":";
        cin>>bt[i];
    }

    int currentTime = 0;
    for(int i =0;i<n;i++){
        if(at[i]<=currentTime){
            currentTime=at[i];
        }
        currentTime+=bt[i];
        ft[i] = currentTime;
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"fcfs scheduling"<<endl;
    cout << "Process\tAT\tBT\tFT\tTAT\tWT\n";
    for(int i =0;i<n;i++){
        cout<<"P"<<i+1<<"\t"
            <<at[i]<<"\t"
            <<bt[i]<<"\t"
            <<ft[i]<<"\t"
            <<wt[i]<<"\t"
            <<tat[i]<<"\t"
            <<endl;

    }
    return 0;
}