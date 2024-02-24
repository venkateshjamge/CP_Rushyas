#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[105];
int dp[105];

// 1d dp;

int recurse(int n, int t) {

	if (t == 0)
		return dp[t] = 0;

	if (dp[t] != -1)
		return dp[t];

	int mn = 1000000000;
//										func1 = n-1 bcoz loop i--; and not taken hence t;
	// if not taken then in the loop func1= recurse(n-1,t) else func = recurse(n, t - a[i]);
	for (int i = n; i >= 1; i--) {
		if (a[i] > t) continue;
		mn = min(mn, 1 + recurse(n, t - a[i]));
	}

	return dp[t] = mn;
}

// 2D dp;

// int dp[105][105];

// int recurse(int n, int t) {
// 	if (t == 0)
// 		return 0;
// 	if (n <= 0 || t < 0)
// 		return 1000000000;

// 	if (dp[n][t] != -1) 
// 		return dp[n][t];

// 	return dp[n][t] = min(recurse(n-1, t), 1 + recurse(n, t - a[n]));
// }

int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));
	
	cout << recurse(n, t) << '\n';

	return 0;
}