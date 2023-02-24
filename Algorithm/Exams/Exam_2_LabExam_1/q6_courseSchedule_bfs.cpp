#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int const N=1000000;
vector<int>g[N];




vector<int> TopoSortBfs(int n){
    int indegree[n+1]={0};
    for(auto i=1;i<=n;i++)
        for(auto node:g[i])
            indegree[node]++;


    queue<int>q;


    for(auto i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
   
    vector<int>topo;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        topo.push_back(top);
        //cout<<top<<" ";


        for(auto node:g[top]){
            indegree[node]--;
            if(indegree[node]==0)
                q.push(node);
        }
    }
    return topo;
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
    }
    vector<int>topoSorted;
    topoSorted=TopoSortBfs(n);


    //cout<<n<<" "<<topoSorted.size()<<endl;


    if(topoSorted.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    //cout<<endl;
    for(int i:topoSorted){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
   
    return 0;
}


/*
Input:


7 6
1 6
6 2
1 3
1 5
5 4
5 7


-------------------
    1-----6-----2
   / \          
  /   \        
 3     5-----4  
      /
     /
    7
-------------------


*/
