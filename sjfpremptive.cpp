#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], ft[n], wt[n], tat[n], rt[n];
    int completed[n] = {0};

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i]; // remaining time initially burst time
    }

    int currentTime = 0, done = 0;

    // shortest job first premptive Execution
    while(done != n)
    {
        int index =-1;
        int time = 1e9;

        for(int i =0;i<n;i++){
            if(!completed[i] && at[i]<=currentTime){
                if(rt[i]<time){
                    time = rt[i];
                    index=i;
                }
            }
        }
        if(index==-1){
            currentTime++;
            continue;
        }
        currentTime++;
        rt[index]--;
        
        // If process finished
        if(rt[index] == 0)
        {
            completed[index] = 1;
            ft[index] = currentTime;
            tat[index] = ft[index] - at[index];
            wt[index] = tat[index] - bt[index];
            done++;
        }
        
    }

    // Output
    cout << "\nRound Robin Scheduling (Preemptive)\n";
    cout << "Process\tAT\tBT\tFT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ft[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    return 0;
}
