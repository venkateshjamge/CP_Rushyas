#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[105];
int dp[105][105];

int recurse(int n, int t) {
	if (t == 0) 
		return dp[n][t] = 1;
	if (n == 0)
		return dp[n][t] = 0;
	if (dp[n][t] != -1) 
		return dp[n][t];

	return dp[n][t] = recurse(n-1, t) + (a[n] <= t ? recurse(n-1, t-a[n]) : 0);
}


int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));

	// the problem is similar to : subset sum diff count;
	// s1 - s2 = diff
	// s1 + s2 = range
	// ------------------
	// s1 = (diff + range) / 2;
	
	// just find out the count of sum = cnt(s1) where s1 = (diff + range) / 2;

	int range = accumulate(a+1, a + n + 1, 0);

	int diff = t;

	int s1 = (diff + range) / 2;

	cout << recurse(n, s1) << '\n';

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= t; j++){
			cerr << dp[i][j] << ' ';
		}
		cerr << '\n';
	}

}