#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

const ll N = 1e6 + 4;

int32_t permutation[N];

mt19937 rng(accuracy);

ll rand(ll l, ll r){
  uniform_int_distribution<ll> uid(l, r); return uid(rng);
}

const ll inf = 1LL << 31;

using pii = pair<ll,ll>;

namespace generator {
    string gen_string(ll len = 0, bool upperCase = false, ll l = 1, ll r = 26) {
        assert(len >= 0 && len <= 5e6);
        string str(len, (upperCase ? 'A' : 'a'));
        for (char &ch: str) {
            ch += rand(l, r) - 1;
        }
        return str;
    }
    vector<ll> gen_array(ll len = 0, ll minRange = 0, ll maxRange = inf){
        assert(len >= 0 and len <= 5e6);
        vector<ll> a(len);
        for (ll &x: a) x = rand(minRange, maxRange);
        return a;
    }
    vector<pair<ll, ll>> gen_tree(ll n = 0){
        assert(n >= 0);
        vector<pii> res(n ? n - 1 : 0);
        // if you like to have bamboo like tree or star like tree uncomment below 8 lines
        /*if (rng() % 5 == 0) { // bamboo like tree
          for (ll i = 1; i < n; ++i) res[i-1] = {i, i + 1};
          return res;
        }
        if (rng() % 7 == 0) { // star tree
          for (ll i = 2; i <= n; ++i) res[i-2] = {1, i};
          return res;
        }*/
        iota(permutation, permutation + 1 + n, 0);
        shuffle(permutation + 1, permutation + 1 + n, rng);
        for(ll i = 2; i <= n; ++i){
            ll u = i, v = rand(1 , i-1);
            u = permutation[u], v = permutation[v];
            res[i-2] = minmax(u, v); // u < v, just for convenience while debugging
        }
        shuffle(res.begin() , res.end() , rng);
        return res;
    }
    vector<pair<ll, ll>> simple_graph(ll n = 0, ll m = 0) {
        assert(n > 0 && m >= n);
        ll max_edges = n * (n - 1) / 2;
        assert(m <= max_edges);
        vector<pii> res = gen_tree(n);
        set<pii> edge(res.begin(), res.end());
        for (ll i = n; i <= m; ++i) {
            while (true) {
              ll u = rand(1, n), v = rand(1, n);
              if (u == v) continue;
              auto it = edge.insert(minmax(u, v));
              if (it.second) break;
            }
        }
        res.assign(edge.begin(), edge.end());
        return res;
    }
}

using namespace generator;

template<typename T = ll>
ostream& operator<< (ostream &other, const vector<T> &v) {
    for (const T &x: v) other << x << ' ';
    other << '\n';
    return other;
}

ostream& operator<< (ostream &other, const vector<pair<ll,ll>> &v) {
    for (const auto &x: v) other << x.first << ' ' << x.second << '\n';
    return other;
}

// comment the just below line if test cases required
#define SINGLE_TEST
const ll max_tests = 10;
const ll maxN = 20;
const ll maxQ = 20;
const ll maxAi=200;

// complete this function according to the requirements
void generate_test() 
{
    ll n = rand(1, maxN);
    cout << n << nl;
    for(int i = 0; i < n; i++){
        cout << rand(1, maxAi) << " ";
    }
    cout << nl;
}


signed main() {
    srand(accuracy);
    ll t = 1;
    #ifndef SINGLE_TEST
        t = rand(1, max_tests), cout << t << '\n';
    #endif
    while (t--) {
        generate_test();
    }
}