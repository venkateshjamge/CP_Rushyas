#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#define dbg(...)
#else
#include <algo/dbg.h>  
#endif
using namespace std;

#define ll long long
#define db double
#define fi first
#define se second
#define nl '\n'
#define vt vector
#define vi vt<int>
#define vl vt<ll>
#define vvi vt<vi>
#define vvl vt<vl>
#define pb push_back
#define pi pair<int, int>
#define sz(x) (ll)(x).size()
#define here() dbg(__LINE__)
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rall(x) (x).rbegin(), (x).rend()
#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))
#define ppc(x) __builtin_popcount(x)
#define ppcll(x) __builtin_popcountll(x)
#define uniq(x) (x).erase(unique(all(x)), (x).end())

const int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
const int Dx[8] = {-1,-1,-1,0,0,1,1,1}, Dy[8] = {-1,0,1,-1,1,-1,0,1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ran(ll l, ll r){uniform_int_distribution<int> uid(l, r); return uid(rng);}

template<typename T,typename T1>T amax(T &a,T1 b){ if (b > a) a = b; return a; }
template<typename T,typename T1>T amin(T &a,T1 b){ if (b < a) a = b; return a; }

const ll inf32 = 1e9, inf64 = 1e18, MOD = 1e9 + 7, N = 200005;

// constuct with a given size (1 : n)
class DSU {
private:
    int n, comps;
    std::vector<int> par;
    std::vector<int> siz;
public: 
    void init(int n) {
        this->n = comps = n;
        siz.assign(n+1,1);
        par.assign(n+1,0);
        std::iota(par.begin(), par.end(),0);
    }

    int find(int x) {
        return (x == par[x]) ? x : par[x] = find(par[x]);  
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (siz[x] < siz[y]) {
                std::swap(x,y);
            }
            par[y] = par[x];
            siz[x] += siz[y];
            comps--;
        }
    }
    
    void print_dsu() {
        dbg(par);
        dbg(siz);
    }
};

 bool canTraverseAllPairs(vector<int>& nums) {
        ll n = nums.size();
        ll MAX = *max_element(nums.begin(), nums.end());
        DSU dsu;
        dsu.init(MAX);
        vector<bool> sve(MAX + 5, 0);
        
        map<ll, bool> mp;
        for(auto x:nums){
            mp[x]=1;
        }
        
        for(int i = 2; i <= MAX; i++)
        {
            if(sve[i] == 1)
                continue;
            
            for(int j = i; j <= MAX; j+=i)
            {
                sve[j] = 1;
                if(mp[j])
                    dsu.unite(i, j);
            }
        }
        
        set<ll> presedents;
        for(auto x:nums)
        {
            presedents.insert(dsu.find(x));
        }
        
        return (presedents.size() == 1);
        
    }

void solve() 
{
    ll n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << canTraverseAllPairs(a);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) 
        solve();
    return 0;
}