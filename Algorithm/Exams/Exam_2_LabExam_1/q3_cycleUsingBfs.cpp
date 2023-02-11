#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
vector<int>g[N];


//checking cycle using topo sort
bool hasCycleBfs(int n){
    //(n+1),as starts from 1
    int indegree[n+1]={0};
    for(auto i=1;i<=n;i++)
        for(auto node:g[i])
            indegree[node]++;

    queue<int>q;

    for(auto i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
    
    int topoNodes=0;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        topoNodes++;

        for(auto node:g[top]){
            indegree[node]--;
            if(indegree[node]==0)
                q.push(node);
        }
    }
    //cout<<topoNodes<<" "<<n<<endl;
    return (topoNodes!=n);
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
    
    if(hasCycleBfs(n))
        cout<<"\nCycle Exists !\n"<<endl;
    else
        cout<<"\nNo Cycle Found !\n"<<endl;


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

7 8
1 6
6 2
1 3
1 5
3 5
4 5
5 7
7 3
-------------------
    1----6-----2
   / \           
  /   \         
 3-----5-----4   
  \    /
   \  /
    7
-------------------

*/