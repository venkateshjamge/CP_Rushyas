/**
  *   author:    dono_whos_this
**/

#ifndef ONLINE_JUDGE
  #include <algo/debug.h>
#else
  #define debug(...) 1
  #include <bits/stdc++.h>
  using namespace std;
#endif

#define ll ll
#define ld long double
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define PB push_back
#define MP make_pair
#define Div(a, b) ((double)(a) / (double)(b))
#define prec(n) fixed << showpoint << setprecision(n)
#define vll vector<ll>
#define pll pair<ll, ll>
#define inf 9e18
#define _inf -9e18
#define mod (ll) 1000000007

const int N = 2e5 + 5;
ll dist[N], parent[N];
bool vis[N];
vector<pair<long, long>> g[N], tree[N];  // tree[u] = {v, w};

ll primsMST(ll source) {
    for (int i = 0; i < N; i++)
        dist[i] = inf;
    set<pair<ll, ll> > s;  // {dist, vertex}
    ll cost = 0;
    dist[source] = 0;
    s.insert({0, source});
    while(!s.empty()) {
        auto& x = *(s.begin());  // dist, vertex pair
        s.erase(x);  
        ll v = x.second;  // v is the current vertex
        ll u = parent[v];
        ll w = x.first;
        vis[v] = true; 
        cost += w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
        for (auto& it : g[v]) {
            // it = g[parent] = {child, w};
            if (vis[it.first]) continue;
            if (dist[it.first] > it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first] = it.second;
                s.insert({dist[it.first], it.first});
                parent[it.first] = v;
            }
        }

    }

    return cost;

}

void solve() {  
    ll n, m;  // n : vertices m : Edges
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // unordered graph // comment if ordered graph
    }
    // need the cost of the MST
    int source;
    cin >> source;
    int cost = primsMST(source);
    cout << "cost: " << cost << endl;
    queue<ll> q;
    memset(vis, 0, sizeof(vis));
    q.push(source);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& it : tree[u]) {
            int v = it.first;
            if (vis[v]) continue;
            cout << u << "->" << v << "  " << it.second << endl;
            q.push(v);
        }
        vis[u] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("ip.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
    int tt = 1;
    // cin >> tt;
    while(tt--) 
      solve();
    return 0;                                                                           
}