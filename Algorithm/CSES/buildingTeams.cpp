/*
Input:

5 3
1 2
1 3
4 5

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
int color[N]={};
int Ncount=0;
vector<int>g[N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};


bool dfs(int src){
    int clr=color[src];
    //cout<<"("<<sx<<","<<sy<<")";
    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    for(int node:g[src]){
        if(color[node]==0){
            if(clr==1)color[node]=2;
            else color[node]=1;

            bool chk=dfs(node);
            if(!chk)return false;
        }
        else if(color[node]==clr){
            //cout<<"IMPOSSIBLE"<<endl;
            return false;
        }
    }

    return true;

}

int main(){
    int m,n;
    cin>>n>>m;

    int p,q;
    for(int i = 0 ; i < m  ; i++) {
        cin>>p>>q;
        g[p].push_back(q);
        g[q].push_back(p);
    }

    bool possible=true;
    for(int i=1;i<=n;i++) {
        if(color[i]==0){
            color[i]=1;
            if(!dfs(i))possible=false;
        }
    }

    if(possible){
        for(int i=1;i<=n;i++) {
            cout<<color[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;

    return 0;
}

/*

5 3
1 2
1 3
4 5

*/

