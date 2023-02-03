#include <bits/stdc++.h>
using namespace std;

void pBfs(vector<vector<int>>graph,int src1,int src2){
    
    int visited[graph.size()]={};
    queue<int>que;

    que.push(src1);
    visited[src1]=1;

    que.push(src2);
    visited[src2]=1;

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
        {1,4},
        {2,0,4},
        {3,1},
        {2,4},
        {0,1,3}
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

    pBfs(g,0,4);

    cout<<endl<<endl;

    return 0;

}
