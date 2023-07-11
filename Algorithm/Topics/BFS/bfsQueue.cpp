#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
vector<int>g[N];
//int previ[N];
int visited[N]={0};



void bfs(int src){
   queue<int>q;
   visited[src]=1;

   q.push(src);

   while(!q.empty()){
    int top=q.front();
    q.pop();

    cout<<top<<" ";
    for(int node:g[top]){
        if(!visited[node]){
            visited[node]=1;
            q.push(node);
        }
    }
   }

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
        //de-comment if undirected
        //g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i])
            bfs(i);
    }
    

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