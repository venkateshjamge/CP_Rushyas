#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>adj[200005];

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	return 0;
}