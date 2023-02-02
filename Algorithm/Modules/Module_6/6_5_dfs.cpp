#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>graph,int visited[],int node){
    
    cout<<node<<" ";
    visited[node]=1;
    
    int adjNodes;
    try{
        adjNodes=graph[node].size();
    }
    catch(...){
        return;
    }


    for(int i=0;i<adjNodes;i++){
        int nextNode=graph[node][i];
        if(!visited[nextNode])
            dfs(graph,visited,nextNode);
    }
}




int main(){
    int nodes=6;
    int v[nodes]={};

    vector<vector<int>>g{
        {2,3,4},
        {2,3},
        {0,1},
        {0,1},
        {0}
        
    };

    g[0].insert(g[0].begin(),5);
    //g[5].push_back(0);

    for(int i=0;i<g.size();i++){
        cout<<i<<" => ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;

    dfs(g,v,1);

    cout<<endl<<endl;

    return 0;

    
}
