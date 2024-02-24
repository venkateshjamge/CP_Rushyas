#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> adj[N];

bool visited[N];

void dfs(int cur){
	if(visited[cur]) return;
	visited[cur]=true;
	debug(cur);
	for(auto child:adj[cur]){
		dfs(child);
	}
}

int main(){
	cin >> n >> m;
	memset(visited,0,sizeof(visited));
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	int MOTHER = -1;
	for(int i = 0; i < n; i++){
		if(visited[i]){
			continue;
		}
		dfs(i);
		MOTHER=i;
	}
	
	// The last i will be the mother 
	// if there are still unvisited vertices after the last mother then surely, the last was not mother
	// and if there are no unvisited vertices after the last mother then the last could be a mother
	// as there are not remaining vertices, still it is possible that there was no path from last to already visited
	// but in any condition, the best candidate to be the mother is the last;=? it can be mother if all vertices are reachable from it;
	// MOTHER is probably a mother;  // if all the vertices are reachable from MOTHER

	// debug(MOTHER);
	memset(visited,0,sizeof(visited));
	dfs(MOTHER);
	/*for(int i = 0; i < n; i++){
		cerr<<visited[i]<<' ';
	}
	cerr<<endl;*/
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			cout<<"No Mother vertex"<<endl;
			return 0;
		}
	}
	cout<<"Mother: "<<MOTHER<<endl;
	return 0;
}