#include <bits/stdc++.h>
using namespace std;
#define ll long long

string n;
ll dp[20][2][200]; // 1<<18

ll helper(int idx, bool tight, ll sum) {
    if(idx==n.size()) {
        return sum;
    }
    if(~dp[idx][tight][sum]) {
        return dp[idx][tight][sum];
    }
    int lastDigit=tight?n[idx]-'0':9;
    ll retVal=0;
    for(int i=0; i<=lastDigit; ++i) {
        bool newTight=tight&&i==(n[idx]-'0');
        retVal+=helper(idx+1, newTight, sum+i);
    }
    return dp[idx][tight][sum]=retVal;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    ll ans = helper(0, 1, 0LL);
    cout << ans << '\n';
}