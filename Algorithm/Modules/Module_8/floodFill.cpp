/*

5 8
########
#.A#...#
#.##.###
#......#
########

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1050;
int visited[N][N]={};
int Ncount=0;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};


   

void dfs(pair<int,int>src,vector<vector<int>>g){
    int gx=g.size(),gy=g[0].size();
    int sx=src.first,sy=src.second;

    visited[sx][sy]=1;
    Ncount++;

    //cout<<"("<<sx<<","<<sy<<")";
    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    for(int i=0;i<4;i++){
        int nx=dx[i]+sx;
        int ny=dy[i]+sy;

        if(nx>-1 && ny>-1 && nx<gx && ny<gy && 
        visited[nx][ny]==0 && g[nx][ny]==0){  
            dfs(make_pair(nx,ny),g);
        }
    }
}

int main(){
    int m,n;
    cin>>n>>m;

    vector<vector<int>>g;
    pair<int,int>src;

    g.resize(n);
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
    }

    for(int i = 0 ; i < n  ; i++) {
        string input;
        cin>>input;
        for(int j = 0 ; j < m ; j++) {
            if(input[j] == '#')g[i][j] = -1;
            else if(input[j] == 'A')src = {i, j};
            else if(input[j] == '.')g[i][j]=0;
        }
    }

    dfs(src,g);
    cout<<Ncount-1<<endl;

    
    return 0;
}

/*

5 8
########
#..#...#
#.##.#A#
#...#..#
########

*/