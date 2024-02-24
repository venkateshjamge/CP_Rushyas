#include <bits/stdc++.h>
using namespace std;

int dp[105][105];  // size of the arrays play important role anywhere 
int n, t;
int a[105];

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
	cout << "target sum count : " << recurse(n, t) << '\n';

	// for(int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= t; j++)
	// 		cerr << dp[i][j] << ' ';
	// 	cerr << '\n';
	// }

	// iterative way to do the same problem:
	// memset(dp, 0, sizeof(dp));

	// int range = accumulate(a+1, a + n + 1, 0);

	// dp[0][0] = 1; // important;

	// cerr << "range: " << range << '\n';


	// this can be made 1-D dp by writing the sum outside and coins inside
	
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= range; j++) {
			
	// 		if (j == 0) {
	// 			dp[i][j] = 1;
	// 			continue;
	// 		}

	// 		if (i == 0) {
	// 			dp[i][j] = 0;
	// 			continue;
	// 		}

	// 		dp[i][j] += dp[i-1][j];

	// 		if (a[i] <= j)
	// 			dp[i][j] += dp[i-1][j - a[i]]; 

	// 	}
	// }

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= range; j++)
	// 		cerr << dp[i][j] << ' ';
	// 	cerr << '\n';
	// }

	// cout << "cnt: " << dp[n][t] << '\n';
	return 0;
}