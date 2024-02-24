#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> adj[N];
bool visited[N];

void dfs(int cur){
	stack<int> s;
	s.push(cur);
	while(!s.empty()){
		int t = s.top(); s.pop();
		if(visited[t]){
			continue;
		}
		cout << t << ' ';
		visited[t] = true;
		for(auto u:adj[t]){
			if(!visited[u]){
				s.push(u);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited, 0, sizeof(visited));
	dfs(0);
	return 0;
}