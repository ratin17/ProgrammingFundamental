#include <bits/stdc++.h>
using namespace std;


void stackDfs(vector<vector<int>>graph,int src){
    int visited[graph.size()]={};
    stack<int>stk;

    stk.push(src);
    visited[src]=1;
    cout<<src<<" ";

    while(!stk.empty()){
        int top=stk.top();
        
        bool completed=true;
        for(int node:graph[top]){
            if(!visited[node]){
                visited[node]=1;
                stk.push(node);
                completed=false;
                cout<<node<<" ";
                break;
            }
        }
        if(completed)stk.pop();
    }

}


int main(){

    vector<vector<int>>g{
        {2,4,5},
        {4,5},
        {0,3,4},
        {2},
        {0,1,2,5},
        {0,1,4}
        
    };

    //g[0].insert(g[0].begin(),5);
    //g[5].push_back(0);
    cout<<endl;
    for(int i=0;i<g.size();i++){
        cout<<i<<" => ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;

    stackDfs(g,1);

    cout<<endl<<endl;

    return 0;

}
