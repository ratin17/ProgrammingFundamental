#include <bits/stdc++.h>
using namespace std;


int const N=1000000;
int const INF=1e9;
vector<int>g[N];
int visited[N]={0};


int dfsLength(int src,int len,int Lmax){
    
    visited[src]=1;
    
    for(int node:g[src]){
        if(!visited[node]){
            Lmax=max(Lmax,len+1);
            int t=dfsLength(node,len+1,Lmax);
            return max(Lmax,t);
        }
    }
    return 0;

}



int main(){

    int n=11;
    
    for(int i=2;i<=n/2;i++){
        for(int j=2*i;j<=n;j=j+i){
             g[i].push_back(j);
        }
    }


    int dfsLen=0;

    for(int i=2;i<=n;i++){
        if(!visited[i]){
            dfsLen=max(dfsLen,dfsLength(i,0,0));
            //cout<<i<<" : "<<dfsLen<<endl;
        }
        //cout<<dfsLen<<endl;
    }
    cout<<"\nLongest path: "<<dfsLen<<endl<<endl;




    return 0;
}

