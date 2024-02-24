#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;

int n, m, s;
vector<pair<int, int> > adj[N];
vector<int> d, p;
vector<bool> vis;


// getting rid of vis array requires the d[pt.top().second] == pq.top().first  // specifies we are operating a functional pair
// another implementation is using std::set
// priority queue version is faster than the set implementation

// void dijkstra() {
// 	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;  // min heap
// 	d.assign(n+1, 1e9);
// 	p.clear(); p.resize(n+1);
// 	vis.assign(n, false);
// 	d[s] = 0;
// 	pq.push({0, s});
// 	while (!pq.empty()) {
// 		int from = pq.top().second; pq.pop();
// 		if (vis[from]) continue;
// 		vis[from] = true;
// 		for (auto pp : adj[from]) {
// 			int to = pp.first, edge = pp.second;
// 			if (d[to] > d[from] + edge) {
// 				// relaxation
// 				d[to] = d[from] + edge;
// 				p[to] = from;
// 				pq.push({d[to], to});
// 			}
// 		}
// 	}
// }

// vis array is not needed as we are deleting the malfunctioned old pairs

void dijkstra() {
	set<pair<int, int> > S;
	d.assign(n+1, 1e9);  // d = inf;
	p.assign(n+1, -1);  // p = -1;
	d[s] = 0;
	S.insert({0, s});
	while(!S.empty()) {
		auto from = S.begin()->second; 
		S.erase(S.begin());
		for (auto pp : adj[from]) {
			int to = pp.first, edge = pp.second;
			if (d[to] > d[from] + edge) {
				// relaxation
				S.erase({d[to], to});
				d[to] = d[from] + edge;
				p[to] = from;
				S.insert({d[to], to});
			} 
		}
	}
}


int32_t main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		// --u; --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra();
	cout << "distance: " << endl;
	for (int i = 0; i < n; i++) {
		cout << d[i] << " \n"[i == n - 1];
	}

	cout << "paths: " << endl;
	for (int i = 0; i < n; i++) {
		vector<int> path;
		for (int start = i; start != -1; start = p[start]) {
			path.push_back(start);
		}
		reverse(path.begin(), path.end());
		cout << i << ": ";
		for (auto v : path) {
			cout << v << " ";
		}
		cout << endl;
	}

	return 0;
}