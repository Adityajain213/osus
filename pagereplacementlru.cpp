#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<unordered_set>
using namespace std;
int main()
{
    int n;
    cout<<"enter size of queue/frames";
    cin>>n;

    list<int> l;
    unordered_set<int> s;

    string st;
    cout<<"enter reference string : ";
    cin>>st;

    int pagefault =0;

    for(int i =0;i<st.size();i++){
        int x = st[i]-'0';
        if(s.find(x)!=s.end()){
            int z = x;
            l.remove(z);
            l.push_back(z);
            continue;
        }
        else{
            pagefault++;

            if(l.size()==n){
                int y = l.front();
                l.pop_front();
                s.erase(y);
            }

            l.push_back(x);
            s.insert(x);
        }
    }
    cout<<pagefault;
    return 0;
}