#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], ft[n], wt[n], tat[n],p[n];
    int completed[n] = {0};   // Track completed processes

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> at[i];

        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> bt[i];

        cout << "Enter priority of process " << i + 1 << ": ";
        cin >> p[i];
    }

    int currentTime = 0;
    int done = 0;

    // SJF logic
    while(done != n)
    {
        int index = -1;
        int priority = -1e9;  // Very large initial burst

        // Find process with smallest burst among arrived + not completed
        for(int i = 0; i < n; i++)
        {
            if(!completed[i] && at[i] <= currentTime)
            {
                if(p[i] > priority)
                {
                    priority = p[i];
                    index = i;
                }
            }
        }

        // If no process has arrived → time moves forward
        if(index == -1)
        {
            currentTime++;
            continue;
        }

        // Execute the selected process
        currentTime += bt[index];
        ft[index] = currentTime;
        tat[index] = ft[index] - at[index];
        wt[index] = tat[index] - bt[index];

        completed[index] = 1;
        done++;
    }

    // Output table
    cout << "\npriority Non-Preemptive Scheduling\n";
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
