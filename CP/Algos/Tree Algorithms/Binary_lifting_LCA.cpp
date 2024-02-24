// it's not about code or how decoratively you write it, it's about mind and what you write, cp is a mind sport
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define debug(...)
#else
#include <algo/debug.h>  
#endif
using namespace std;
 
#define ll                  long long
#define nl                  '\n'
#define pb                  push_back
#define f                   first
#define s                   second
#define vt                  vector
#define vll                 vt<ll> 
#define pb                  push_back
#define vvll                vt<vt<ll>>
#define pll                 pair<ll,ll>
#define vpll                vt<pll>
#define vvpll               vt<vt<pll>>
#define sz(x)               (ll)(x).size()
#define here()              debug(__LINE__)
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define mem0(x)             memset(x,0,sizeof(x))
#define mem1(x)             memset(x,-1,sizeof(x))
#define loop(x,a)           for (auto &x : a)
#define for0(i,n)           for (ll i = 0; i < n; i++)
#define for1(i,n)           for (ll i = 1; i <= n; i++)
#define YES(x)              cout << (x ? "YES" : "NO") << nl;
 
template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }
 
void solve();
 
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
 
const ll INF64 = 1e18;
const int INF32 = 1e9;
const ll MOD = 1e9+7;
const ll N = 2e5 + 5; 
 
ll n, q;
vll parent;
vvll adj;
vvll up;
vll tin, tout;
ll timer = 0;
vll dis;
   
void binary_lifting(ll cur, ll par) {
    up[cur][0] = par;

    for(int i = 1; i < 20; i++) {
        if(up[cur][i - 1] == -1)
            up[cur][i] = -1;
        else
            up[cur][i] = up[up[cur][i - 1]][i - 1];
    }

    loop(child, adj[cur]) {
        if(child == par) 
            continue;
        binary_lifting(child, cur);
    }
}
 
void dfs(ll cur, ll par, ll D = 0) {
    tin[cur] = ++timer;
    dis[cur] = D;
    loop(child, adj[cur]) {
        if(child == par)
            continue;
        dfs(child, cur, D + 1);
    }
    tout[cur] = ++timer;
}
 
bool is_ancestor(ll x, ll y) {
    return tin[y] >= tin[x] && tout[y] <= tout[x];
}

ll LCA(ll x, ll y) {
    if(is_ancestor(x, y)) {
        return x;
    }
    else if(is_ancestor(y, x)) {
        return y;
    }
    for(int i = 19; i >= 0; i--) {
        ll lifted_node = up[x][i];
        if(lifted_node == -1 || is_ancestor(lifted_node, y))
            continue;
        x = lifted_node;
    }
    return up[x][0];
}

// graph algos + string algos + range query algos + oops + dbms + os+ system design
 
void solve() {
    cin >> n >> q;
    tin = tout = parent = vll(n + 1);
    adj = vvll(n + 1);
    up = vvll(n + 1, vll(20, -1));
    dis = vll(n + 1, 0);
    for1(i, n - 1)  {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }   

    timer = 0;
    dfs(0, -1);

    binary_lifting(0, -1);

    for0(i, q) {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        ll lca = LCA(x, y);
        debug(x, y, lca);
        ll ans = dis[x] + dis[y] - 2 * dis[lca];
        cout << ans << nl;
    }   

}