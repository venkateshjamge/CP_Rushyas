#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, m, s;
vector<pair<int, pair<int, int>>> edges;
vector<int> d, p;

void bellman_ford() {
	d.assign(n+1, 1e9);
	p.assign(n+1, -1);
	d[s] = 0;
	// run this loop for the nth time and if there is still relaxation then the 
	// graph has the negative cycle
	for(int i = 1; i <= n - 1; i++) {
		bool any = false;
		for(auto &it : edges){
			int u = it.first, v = it.second.first, w = it.second.second;
			// make sure U is reachable node
			if(d[u] >= 1e9) {
				continue;
			} 
			if(d[v] > d[u] + w) {
				// relaxation
				d[v] = d[u] + w;
				p[v] = u;
				any = true;
			}
		}
		if (!any) break;
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, {v, w}});
	}
	bellman_ford();

	return 0;
}