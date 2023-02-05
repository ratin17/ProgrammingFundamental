#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>graph,int src){
    
    int visited[graph.size()]={};
    queue<int>que;

    que.push(src);
    visited[src]=1;

    while(!que.empty()){

        int head=que.front();
        que.pop();
        cout<<head<<" ";

        for(int node:graph[head]){
            if(!visited[node]){
                que.push(node);
                visited[node]=1;
            }
        }
    }

}


int main(){


    vector<vector<int>>g{
        {0,3,2,3,4},
        {2,3},
        {0,1},
        {0,1},
        {0},
        {}
        
    };

    //g[0].insert(g[0].begin(),5);
    //g[5].push_back(0);


    for(int i=0;i<g.size();i++){
        cout<<i<<" => ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;

    bfs(g,1);

    cout<<endl<<endl;

    return 0;

}
