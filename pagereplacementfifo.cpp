#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_set>
using namespace std;
int main()

{
    // int n;
    // cout<<"enter number of processes ";
    // cin>>n;

    int size;
    cout<<"enter size of queue: ";
    cin>>size;

    queue<int> q;
    unordered_set<int> s;

    string x;
    cout<<"enter reference string: ";
    cin>>x;

    int pagefault = 0;
    for(int i =0;i<x.size();i++){
        int y = x[i]-'0';

        if(s.find(y)!=s.end()){
            continue;
        }
        else{
            pagefault++;

            if(q.size()==size){
            int z = q.front();
            q.pop();
            s.erase(z);
            }

            q.push(y);
            s.insert(y);


        }
    }

    cout<<pagefault;
    return 0;
}