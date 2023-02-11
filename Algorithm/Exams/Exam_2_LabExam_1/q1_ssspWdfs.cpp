#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int const N=1000000;
vector<int>g[N];
int level[N]={-1};
int visited[N]={};



void dfs(int src){
    visited[src]=1;
    for(int node:g[src]){
        if(visited[node])
        level[node]=min(level[node],level[src]+1);
        else level[node]=level[src]+1;
        //**No checking for visited or not**
        dfs(node);
    }
}


int main(){
    int n,m,src;
    //Enter number of nodes and edges
    cin>>n>>m;
    int a,b;
    //Enter Edges: src --> dest
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }
    //Enter source
    cin>>src;

    for(int i=1;i<=n;i++)level[i]=-1;

    level[src]=0;

    dfs(src);

    //Printing Output
    cout<<"\nNodes:\t";
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }

    cout<<"\nSSSP:\t";
    for(int i=1;i<=n;i++){
        if(level[i]==-1)
        cout<<"X ";
        else
        cout<<level[i]<<" ";
    }
    cout<<endl<<endl;

    return 0;

}

/*
Input: 

7 6
6 2
1 3
1 5
3 5
5 4
5 7
1
-------------------
    1      6-----2
   / \           
  /   \         
 3-----5-----4   
      /
     /
    7
-------------------

*/