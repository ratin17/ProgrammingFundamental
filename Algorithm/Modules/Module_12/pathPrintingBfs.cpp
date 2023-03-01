#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
vector<int>g[N];
int previ[N];
int visited[N]={0};

string printPath(int start,int node,int count){
    // cout<<"Inside PrintCyc"<<endl;
    // cout<<"--"<<node<<" ";
    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    if(node==start){
        cout<<count+1<<endl;
        return to_string(node);
    }

    return 
    printPath(start,previ[node],count+1)+" "+to_string(node);
}



bool bfs(int src,int dest){
   queue<int>q;
   visited[src]=1;

   q.push(src);

   while(!q.empty()){
    int top=q.front();
    q.pop();

    //cout<<top<<" ";
    for(auto node:g[top]){
        if(!visited[node]){
            visited[node]=1;
            q.push(node);
            previ[node]=top;
            if(node==dest){
                string s;
                s=printPath(1,node,0);
                cout<<s<<endl;
                return true;
            }
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
    
    if(!bfs(1,n))cout<<"IMPOSSIBLE"<<endl;
    
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