#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
int const N=1000;
int visited[N][N]={0};
int L[26]={0};
int g[N][N]={};
int Ncount=0;
int n,m;
 
int dx[]={1,-1,0,0,-1,1,-1,1};
int dy[]={0,0,1,-1,-1,-1,1,1};
 
 
   
 
int dfs(int sx,int sy,int len,int Lmax){
    int gx=n,gy=m;
 
    visited[sx][sy]=1;
    L[g[sx][sy]]=1;
 
    //cout<<g[sx][sy]<<endl;
    //cout<<"("<<sx<<","<<sy<<")";
    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);
 
    for(int i=0;i<8;i++){
 
        int nx=dx[i]+sx;
        int ny=dy[i]+sy;
 
        if(nx>-1 && ny>-1 && nx<gx && ny<gy && 
        !visited[nx][ny] && !L[g[nx][ny]]&&
        g[nx][ny]-g[sx][sy]==1){
 
            Lmax=max(Lmax,len+1);
            int t=dfs(nx,ny,len+1,Lmax);
            return max(Lmax,t);
 
        }
    }
    return 0;
}
 
int main(){
    int t=0;
    while(true){
    cin>>n>>m;
    if(n==0&&m==0)break;
    t++;
 
    vector<pair<int,int>>src;
 
    for(int i = 0 ; i < n  ; i++) {
        string input;
        cin>>input;
        for(int j = 0 ; j < m ; j++) {
            g[i][j]=int(input[j])-65;
            if(g[i][j]==0){
                src.push_back({i,j});
            }
        }
    }
 
    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
 
   int dfsLen=0;
 
    for(pair<int,int>s:src){
        int i=s.first;
        int j=s.second;
        if(!visited[i][j]){
            for(int k=0;k<26;k++){
                L[k]=0;
            }
            dfsLen=max(dfsLen,dfs(i,j,0,0));
            //cout<<g[i][j]<<" : "<<dfsLen+1<<endl;
        }
        //cout<<dfsLen<<endl;
    }
    cout<<"Case "<<t<<": "<<dfsLen+1<<endl;
 
    }
 
    return 0;
}
 
 
 
/*
4 3
ABE
CFG
BDH
ABC
 
*/