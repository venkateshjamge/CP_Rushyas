#include  <bits/stdc++.h>
using namespace std;

int n, t;
int a[105];
int dp[105][105];

int recurse(int n, int t) {
	if (t == 0) return dp[n][t] = 1;
	if (n <= 0 || t < 0) return dp[n][t] = 0;

	if (dp[n][t] != -1) return dp[n][t];

	return dp[n][t] = recurse(n-1, t) + recurse(n, t - a[n]);
}

int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];

	memset(dp, -1, sizeof(dp));
	cout << recurse(n, t) << '\n';
	for (int i = 0; i <= n; i++) 
	{
		for (int j = 0; j <= t; j++)
			cerr << dp[i][j] << ' ';
		cerr << '\n';
	}

	return 0;

}