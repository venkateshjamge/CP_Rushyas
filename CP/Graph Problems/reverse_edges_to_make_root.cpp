// https://www.geeksforgeeks.org/minimum-edge-reversals-to-make-a-root/

#ifdef ONLINE_JUDGE
    #include <bits/stdc++.h>
    #define debug(...) 
#else
    #include <d2x/dy2.h>
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr(i, a, b) for (int i = (int)(a), _fg_ = 1; _fg_; _fg_= (i != b), b > a ? ++i : --i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define ll long long
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef long double ld;

template<class T> istream& operator>>(istream& is,vector<T>& v) {for(int i=0;i<sz(v);i++) is>>v[i];return is;}
template<typename Arg1>long long uin(Arg1&& arg1) {return (long long) arg1;}template<typename Arg1, typename... Args>long long uin(Arg1&& arg1, Args&&... args) {return min((long long)arg1, (long long)uin(args...));}
template<typename Arg1>long long uax(Arg1&& arg1) {return (long long) arg1;}template<typename Arg1, typename... Args>long long uax(Arg1&& arg1, Args&&... args) {return max((long long)arg1, (long long)uax(args...));}

#ifdef ONLINE_JUDGE
    template<class T> ostream& operator<<(ostream& os,vector<T>& v) {for(auto& i : v) os<<i<<' ';return os;}
#endif

const int mod = 1e9+7; // 998244353
const ld pi = acos(-1);
const int inf = 1e9;
const ll inff = 9e18;
const ll maxn = 1e12 + 1;


int n;
vector<vpii> adj;
vpii D;

void dfs(int cur, int par = 0, int d = 0, int r = 0) {
	// debug(cur, par);
	for(auto child : adj[cur]) {
		if (child.fi == par) continue;
		D[child.fi].fi = d + 1;
		if (child.se == 1) D[child.fi].se = r + 1;
		else D[child.fi].se = r;
		dfs(child.fi, cur, D[child.fi].fi, D[child.fi].se);
	}
}

// use for cl_rsz in graphs:
template<typename Arg1>void prep(Arg1&& arg1) {(arg1).clear(); arg1.resize(n+1);}template<typename Arg1, typename... Args>void prep(Arg1&& arg1, Args&&... args) {(arg1).clear(); arg1.resize(n+1);prep(args...);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                                             
    cout.precision(10);
    cout << fixed;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        prep(adj, D);

        forn(i, n-1) {
        	int u, v;
        	cin >> u >> v;
        	adj[u].pb({v, 0});
        	adj[v].pb({u, 1});
        }
        
        // // this graph will always be without forming cycles as it's a tree 
        // // but it won't also have > 1 path from a to b where a, b ∈ V
        // // so the distance will the final once visited;


        dfs(0);  // dfs started from a random vertex, could be 1, 2, 3, ... 7;

        int total_rev = 0;
        forn(i, n) {
        	if (D[i].se > total_rev) {
        		total_rev = D[i].se;
        	}
        }

        debug(D);

        int revmin = inf, root = -1;
        forn(i, n) {
        	int revfromitostart = D[i].fi - D[i].se;
        	int revfromallothertoi = total_rev - D[i].se;
        	if (revmin > revfromitostart + revfromallothertoi) {
        		revmin = revfromallothertoi + revfromitostart;
        		root = i;
        	}
        }
        cout << revmin << "\n";
}
    
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}


/*
IN:
8
0 1
2 1
3 2
3 4
5 4
5 6
7 6
*/