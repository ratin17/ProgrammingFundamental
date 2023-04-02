#include<bits/stdc++.h>
using namespace std;
#define INF ((int)(1e9+7))
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> v[n];
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		x--,y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int k;
	cin >> k;
	queue<int> q;
	vector<int> visited(n,false);
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		x--;
		q.push(x);
		visited[x] = true;
	}	
	//given k>1
	int time = 0;
	int last;
	while(!q.empty()){
		int size = q.size();
		vector<int> in_this_level;
		while(size--){
			int s = q.front();
			q.pop();
			for(auto x : v[s]){
				if(!visited[x]){
					visited[x] = true;
					in_this_level.push_back(x);
					last = x;
					q.push(x);
				}
			}
		}
		if(in_this_level.size())time++;
		for(auto y : in_this_level)
			last = min(last,y);
	}
	cout << time << endl << last+1 << endl;
}