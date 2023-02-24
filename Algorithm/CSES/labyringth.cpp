/*

5 8
########
#.A#...#
#.##.#B#
#......#
########

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1050;
//int g[N][N];
vector<vector<int>>g(N,vector<int>(N));
int visited[N][N]={};
int level[N][N];
int n,m;

//vector<vector<pair<int,int>>>previ(N);
vector<vector<pair<int, int>>> previ(N, vector<pair<int, int>>(N));
//pair<int,int> prev[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void path(pair<int,int>s,pair<int,int>d){
    int dx=d.first,dy=d.second;

    if(dx==s.first && dy==s.second)return;

    int px=previ[dx][dy].first;
    int py=previ[dx][dy].second;

   
    path(s,previ[dx][dy]);

    if(px==dx &&py<dy)cout<<"R";
    else if(px==dx && py>dy)cout<<"L";
    else if(px<dx && py==dy)cout<<"D";
    else if(px>dx && py==dy)cout<<"U";


    //cout<<"("<<px<<","<<py<<")";

    

    //cout<<"("<<dx<<","<<dy<<")";

}

void bfs(pair<int,int>src,pair<int,int>dst){
    queue<pair<int,int>>que;

    int gx=n;
    int gy=m;

    visited[src.first][src.second]=1;
    level[src.first][src.second]=0;

    que.push(src);

    while(!que.empty()){
        pair<int,int>head=que.front();
        que.pop();

        int x=head.first,y=head.second;
        if(x==dst.first && y==dst.second)return;

        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;

            if(nx>-1 && ny>-1 && nx<gx && ny<gy && 
                visited[nx][ny]==0 && g[nx][ny]==0){
                
                visited[nx][ny]=1;
                level[nx][ny]=level[x][y]+1;
                pair<int,int>temp={nx,ny};
                previ[nx][ny]=head;
                que.push(temp);

            }
        }


    }
}

int main(){
    cin >> n >> m;

    pair<int, int>src, dst;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            level[i][j] = -1;
        }
    }

    for(int i = 0 ; i < n  ; i++) {
        string input;
        cin>>input;
        for(int j = 0 ; j < m ; j++) {
            if(input[j] == '#')g[i][j] = -1;
            else if(input[j] == 'A')src = {i, j};
            else if(input[j] == 'B')dst = {i, j};
        }
    }


    bfs(src,dst);

    if(visited[dst.first][dst.second]){
        cout<<"YES"<<endl;
        cout<<level[dst.first][dst.second]<<endl;
        path(src,dst);
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}
