#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<list>
#include<unordered_set>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of frames : ";
    cin>>n;

    list<int> l;
    set<int>s;

    string st;
    cout<<"enter reference string: ";
    cin>>st;

    int pagefault =0;
    for(int i =0;i<st.size();i++){
        int x = st[i]-'0';
        if(s.find(x)!=s.end()){
            continue;
        }
        else{
            pagefault++;

            if(l.size()<n){
                l.push_back(x);
                s.insert(x);
                continue;
            }

            //important for finding optimal 
            int replace =-1;
            int index=-1;

            for(auto ele:l){
                int next =-1;
                for(int j =i+1;j<st.size();j++){
                    if(x==ele){
                        next = j;
                        break;
                    }
                }
                if(next==-1){
                    replace = ele;
                    break;
                }

                if(next>index){
                    index = next;
                    replace=ele;
                }
            }

            int z = replace;
            l.remove(z);
            s.erase(z);


            l.push_back(x);
            s.insert(x);

            

        }
    }
    cout<<pagefault;
    return 0;
}