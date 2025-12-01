#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int allocation[n][m];
    int maxneed[n][m];
    int need[n][m];
    int available[m];

    int completed[n] = {0};   // Tracks completed processes
    vector<int> safe;         // Stores safe sequence

    // ----- Allocation Matrix Input -----
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter allocation for P" << i << " Resource " << j << ": ";
            cin >> allocation[i][j];
        }
    }

    // ----- Max Need Matrix Input -----
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter max need for P" << i << " Resource " << j << ": ";
            cin >> maxneed[i][j];
        }
    }

    // ----- Available Resources Input -----
    cout << "Enter available resources: ";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }

    // ----- Need = Max - Allocation -----
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxneed[i][j] - allocation[i][j];
        }
    }

    // ----- Banker's Algorithm -----
    int done = 0;

    while (done != n)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (!completed[i])   // only check unfinished processes
            {
                bool possible = true;

                // Check if need <= available
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        possible = false;
                        break;
                    }
                }

                // If the process can execute safely
                if (possible)
                {
                    for (int j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];  // release resources
                    }

                    safe.push_back(i);
                    completed[i] = 1;
                    done++;
                    found = true;
                }
            }
        }

        // If no process could run in this loop -> unsafe
        if (!found)
        {
            cout << "\nNo SAFE sequence possible. System is in UNSAFE state.\n";
            return 0;
        }
    }

    // ----- Print Safe Sequence -----
    cout << "\nSAFE sequence: ";
    for (int i = 0; i < safe.size(); i++)
    {
        cout << "P" << safe[i];
        if (i != safe.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    return 0;
}
