#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int const N=1000000;
int visited[N]={};
int previ[N]={};
int Ncount=0;

vector<int>g[N];

string printCycle(int start,int node,int count){
    // cout<<"--"<<node<<" ";

    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    if(node==start){
        cout<<count+1<<endl;
        return to_string(node);
    }

    return printCycle(start,previ[node],count+1)+" "+to_string(node);
}


bool dfs(int src){
    visited[src]=1;
    //cout<<src<<endl;

    for(int node:g[src]){
        previ[node]=src;
        //cout<<node<<" "<<previ[node]<<endl;
        if(!visited[node]){
            bool cyc=dfs(node);
            if(cyc)return true;
        }
        else if(visited[node]==1){
            //cout<<"start "<<node<<" "<<previ[node]<<endl;
            cout<<printCycle(node,previ[node],1);
            cout<<" "<<node<<endl;
            return true;
        }
    }

    visited[src]=2;

    return false;

}


int main(){
    int n,m;
    cin>>n>>m;
   
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }

    // for(int i=0;i<=n;i++){
    //     cout<<i<<" => ";
    //     for(int j=0;j<g[i].size();j++){
    //         cout<<g[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    bool cycle=false,k;
    for(int i=1;i<=n;i++){
        // cout<<i<<": i"<<endl;
        if(!visited[i]){
            k=dfs(i);
            if(k){
                cycle=true;
                break;
            }
        }
    }

    if(!cycle)cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
