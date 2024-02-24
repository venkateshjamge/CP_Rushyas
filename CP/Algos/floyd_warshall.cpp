#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> mat, p;

void FLOYD(){
	// O(N^3)
	// mind the order : k -> i -> j
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				// ensure that k is reachable from i and j so that i -> k && then k -> j
				if(mat[i][k] < 1e9 && mat[k][j] < 1e9){
					if(mat[i][j] > mat[i][k] + mat[k][j]){
						mat[i][j] = mat[i][k] + mat[k][j];
						p[i][j] = k;
					}
				}
			}	
		}
	}
}

int main() {
	cin >> n >> m;
	adj.clear();
	adj.resize(n+1);
	// 1 based indexing for vertices
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		// adj[v].push_back({u, w});  // for undirected graph
	}
	mat.assign(n+1, vector<int> (n+1, 1e9));
	p.assign(n+1, vector<int> (n+1, -1));

	for(int i = 1; i <= n; i++){
		mat[i][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(auto u:adj[i]){
			mat[i][u.first] = u.second; 
		}
	}

	FLOYD();

	// printing distance matrix;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << mat[i][j] << " \n"[j == n];
		}
	}

	// printing penultimate vertex matrix	
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		cout << p[i][j] << " \n"[j == n];
	// 	}
	// }

	// printing shortest path from start to end vertex 
	int start, end;
	cin >> start >> end;
	cout << start << " ";
	while(p[start][end] != -1){
		cout << p[start][end] << " ";
		start = p[start][end];
	}
	cout << end << " ";
	return 0;
}