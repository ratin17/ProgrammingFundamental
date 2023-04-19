#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
using PII = pair<int, int>;

int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];

int d[N]={0};


int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> dis(n+1, INT_MAX), dis2(n+1, INT_MAX);
        vector<vector<int>> graph(n + 1);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dis[1] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.emplace(0, 1);
        while (pq.size()) {
            auto [cost, node] = pq.top();pq.pop();
            if (dis2[node] < cost) continue;
            for (auto nei: graph[node]) {
                int new_cost = cost + time;
                // red
                if ((cost / change) % 2 == 1){
                    new_cost += change - (cost % change);
                }
                if (dis[nei] > new_cost){
                    dis2[nei] = dis[nei];
                    dis[nei] = new_cost;
                    pq.emplace(new_cost, nei);
                } else if (new_cost > dis[nei] && new_cost < dis2[nei] ) {
                    dis2[nei] = new_cost;
                    pq.emplace(new_cost, nei);
                }
            }
        }
        return dis2[n];
    }

int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin>>T;
    for(int x=1;x<=T;x++){
        int n,m,t;
        //Enter number of nodes and edges
        cin>>n>>m;
        int a,b,w;
        //Enter Edges: src --> dest
        for(int i=0;i<m;i++){
            cin>>a>>b>>w;
            g[a].push_back({b,w});
            //de-comment if undirected
            g[b].push_back({a,w});
        }

        cin>>t;

        printf("Case %d:\n",x);
        

        for(int z=0;z<n;z++){
            g[z].clear();
        }
    }

    return 0;
}


/*

2

5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8
1

5 4
0 1 5
0 1 4
2 1 3
3 4 7
1

------------------

2

5 4
0 1 5
0 1 4
2 1 3
3 4 7
1

5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8
1

*/


