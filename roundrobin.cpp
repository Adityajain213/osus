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

    int qt;
    cout << "Enter time quantum: ";
    cin >> qt;

    queue<int> q;
    int currentTime = 0, done = 0;

    // Push all processes arriving at time 0 into queue
    for(int i = 0; i < n; i++)
    {
        if(at[i] == 0)
            q.push(i);
    }

    // Round Robin Execution
    while(done != n)
    {
        // No process available → time forward
        if(q.empty())
        {
            currentTime++;
            for(int i = 0; i < n; i++)
            {
                if(at[i] == currentTime)
                    q.push(i);
            }
            continue;
        }

        int index = q.front();
        q.pop();

        // Run process for quantum or remaining burst
        int time = min(rt[index], qt);
        rt[index] -= time;
        int start = currentTime;
        currentTime += time;

        // Add newly arrived processes during execution interval
        for(int i = 0; i < n; i++)
        {
            if(at[i] > start && at[i] <= currentTime && !completed[i])
                q.push(i);
        }

        // If process finished
        if(rt[index] == 0)
        {
            completed[index] = 1;
            ft[index] = currentTime;
            tat[index] = ft[index] - at[index];
            wt[index] = tat[index] - bt[index];
            done++;
        }
        else
        {
            q.push(index); // not completed → put at end of queue
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
