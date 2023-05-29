#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=10;
const int INF=INT32_MAX;


int vis[N][N];
int lvl[N][N];


int bfs(pair<int,int>src,pair<int,int>dst){

    if(src==dst)return 0;

   queue<pair<int,int>>q;

   int sx,sy,dx,dy;
   
   sx=src.first;
   sy=src.second;
   dx=dst.first;
   dy=dst.second;




   vis[sx][sy]=1;
   lvl[sx][sy]=0;

   q.push(src);

   while(!q.empty()){
    pair<int,int>top=q.front();
    q.pop();

    int x,y,X=top.first;
    int Y=top.second;

    x=X-2,y=Y+1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }

    x=X-2,y=Y-1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }


    x=X+2,y=Y+1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }

    x=X-2,y=Y-1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }

    y=Y-2,x=X+1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }

    
    y=Y-2,x=X-1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }

    
    y=Y+2,x=X+1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }

    
    y=Y+2,x=X-1;
    if(x>=0&&x<8&&y>=0&&y<8&&vis[x][y]==0){
        vis[x][y]=1;
        lvl[x][y]=lvl[X][Y]+1;
        if(x==dx&&y==dy)return lvl[x][y];
        q.push(make_pair(x,y));
    }
 

    }
    return -1;
}



int main(){

    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;


    pair<int,int>src,dest;
    src=make_pair(sx,sy);
    dest=make_pair(tx,ty);


    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            vis[i][j]=0;
        }
    }

    cout<<bfs(src,dest)<<endl;


    return 0;
}


/*
Input


0 0 3 3


*/