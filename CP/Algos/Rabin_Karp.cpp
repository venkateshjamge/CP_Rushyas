#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int D = 10;  // this is the total number of possible characters in the string to be matched and the source
const int MOD = 1e9 + 7;

int add(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int mult(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int sub(int a, int b) {
    return ((a % MOD - b % MOD) + MOD ) % MOD;
}

int exp(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int Hash(string str) {
    int res = 0;
    int sz = str.size();
    for (int i = 0; i < sz; i++) {
        res = add(mult(res, D), (int) str[i]);  // res = res * D + str[i]     
    }

    return res;
} 

int32_t main(){
    string src, pat;
    cin >> src >> pat;
    int n = src.size(), m = pat.size();
    int h = exp(D, m - 1);
    cout << "h: " << h << endl;
    int hs = Hash(src.substr(0, m));
    int hp = Hash(pat);
    cout << "Hs1 : " << hs << endl;
    cout << "hp: " << hp << endl;                                                                   
    vector<int> ans;
    if (hs == hp and src.substr(0, m) == pat) {
        ans.push_back(0);
    }
    for (int i = 0; i <= n - m; i++) {
        hs = sub(hs, mult((int) src[i], h)); // remove the first dig
        hs = add(mult(hs, D), src[i+m]);
        cout << "hs: " << hs << endl;
        if (hp == hs && src.substr(i+1,m) == pat) {
            ans.push_back(i+1);
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}