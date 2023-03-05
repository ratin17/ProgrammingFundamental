#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
vector<int>g[N];
int previ[N];
int visited[N]={0};
int cat[N]={0};
int ans=0;


void Dfs(int src,int c,int l){
    //cout<<src<<"U"<<c<<endl;
    visited[src]=1;
    
    bool leaf=true;
    for(auto node:g[src]){

        if(!visited[node]){
            leaf=false;
            int z=c;

            if(cat[node])z++;
            else z=0;

            //cout<<node<<"D"<<z<<endl;
            if(z<=l)Dfs(node,z,l);
        }

    }
    if(leaf){
        ans++;
        //cout<<"leaf : "<<src<<"->"<<ans<<endl;
    }
}


int main(){
    int n,m,c;
    //Enter number of nodes and edges
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>cat[i];
    int a,b;
    //Enter Edges: src --> dest
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    Dfs(1,cat[1],m);
    cout<<ans<<endl;
    

    return 0;
}


/*
Input:

7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7

*/