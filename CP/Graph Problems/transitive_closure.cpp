#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> adj[N];

int cno = 1;


void dfs(int cur, int par, vector<vector<int>>& trans){
	debug(cno, cur, par);
	cno++;
	trans[par][cur] = 1;   // cur == par for all the calls from the solve function
	for(auto child:adj[cur]){
			if(trans[par][child] == 0){
				/*if(child == par){
					trans[par][child] = 1;
				} else{
					dfs(child, par, trans);	
				}*/
				dfs(child, par, trans);
			}		
	}
}



int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	vector<vector<int>> trans(n, vector<int> (n, 0));

	for (int i = 0; i < n; i++){
		dfs(i, i, trans);
	}
	for(auto &it:trans){
		for(auto i:it){
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}