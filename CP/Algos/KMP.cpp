/**
  *   author:    dono_whos_this
**/

#ifndef ONLINE_JUDGE
  #include <d2x/dy2.h>
#else
  #define debug(...) 1
  #include <bits/stdc++.h>
  using namespace std;
#endif

#define ll long long
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

vector<long long> calculate_prefix(string &cur) {
    vector<long long> pi (cur.length(), 0);
    for (int i = 1; i < cur.length(); i++) {
        int j = pi[i - 1];
        while(j > 0 && cur[i] != cur[j]) {
            j = pi[j - 1];
        }
        if (cur[i] == cur[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<long long> KMP(string &text, string &pattern) {
    string cur = pattern + '#' + text;
    vector<long long> lps = calculate_prefix(cur);
    debug(lps);
    vector<long long> res;
    long long sz1 = pattern.length();
    long long sz2 = text.length();
    for (int i = sz1 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz1) {
            res.push_back(i - (2 * sz1));
        }
    }
    return res;
}
    
void solve() {  
    string text, pattern;
    cin >> text >> pattern;
    vector<ll> res = KMP(text, pattern);
    cout << "Pattern matched at: ";
    for (auto& it : res) cout << it << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    // while(tt--) 
      solve();
    return 0;                                                                           
}