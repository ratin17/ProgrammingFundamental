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




bool bfs(int src){
   queue<int>q;
   visited[src]=1;


   q.push(src);


   while(!q.empty()){
    int top=q.front();
    q.pop();


    //cout<<top<<" ";
    for(auto node:g[top]){
        if(!visited[node]){
            previ[node]=top;
            visited[node]=1;
            q.push(node);
        }
        else if(previ[top]!=node){
            int p=previ[top];
            previ[p]=top;
            previ[top]=node;
            //cout<<node<<"--"<<src<<endl;
            cout<<printCycle(node,previ[node],1);
            cout<<" "<<node<<endl;
            return true;
        }
    }
   }


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
        //de-comment if undirected
        g[b].push_back(a);
    }


    bool cycle=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){


            if(bfs(i)){
                //cout<<"Cycle"<<endl;
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


7 7
1 3
3 4
3 5
5 6
4 2
4 7
2 7




*/
