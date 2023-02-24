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
vector<int>g[N];
int color[N]={};
stack<int>st;


bool dfsCycle(int src){

    //cout<<src<<endl;

    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    for(int node:g[src]){
        if(color[node]==0){
            color[node]=1;
            bool chk=dfsCycle(node);
            if(chk)return true;
        }
        else if(color[node]==1){
            return true;
        }
    }

    color[src]=2;
    st.push(src);
    return false;


}

int main(){
    int m,n;
    cin>>n>>m;

    int a,b;
    for(int i = 0 ; i < m  ; i++) {
        cin>>a>>b;
        g[a].push_back(b);
    }

    bool possible=true;
    for(int i=1;i<=n;i++) {
        if(color[i]==0){
            color[i]=1;
            if(dfsCycle(i)){
                possible=false;
                break;
            }
        }
    }

    if(possible){
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
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

