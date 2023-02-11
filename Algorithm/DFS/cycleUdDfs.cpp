#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
vector<int>g[N];
int previ[N];
int visited[N]={0};


string printCycle(int start,int node,int count){
    // cout<<"Inside PrintCyc"<<endl;
    // cout<<"--"<<node<<" ";
    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    if(node==start){
        cout<<count+1<<endl;
        return to_string(node);
    }

    return printCycle(start,previ[node],count+1)+" "+to_string(node);
}



bool hasCycleDfs(int src){
    visited[src]=1;
    //cout<<" "<<src<<endl;

    for(auto node:g[src]){
        if(!visited[node]){
            previ[node]=src;
            if(hasCycleDfs(node))
                return true;
        }
        if(visited[node]==1){
            //cout<<node<<" ";
            if(previ[src]!=node){
                previ[node]=src;
                //cout<<node<<"--"<<src<<endl;
                cout<<printCycle(node,previ[node],1);
                cout<<" "<<node<<endl;
                return true;
            }
        }
    }
    visited[src]=2;
    return false;
}


int main(){
    int n,m;
    //Enter number of nodes and edges
    cin>>n>>m;
    int a,b;
    //Enter Edges: src --> dest
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bool cycle=false;
    for(int i=1;i<=n;i++){
        // cout<<i<<": i"<<endl;
        if(!visited[i]){
            if(hasCycleDfs(i)){
                cycle=true;
                break;
            }
        }
    }

    if(!cycle)cout<<"IMPOSSIBLE"<<endl;

    return 0;
}


/*
Input:

5 6
1 3
1 2
5 3
1 5
2 4
4 5

*/