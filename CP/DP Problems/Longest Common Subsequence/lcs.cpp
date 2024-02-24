#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[105][105];

// int recurse(int n, int m) {
// 	if (n == 0 || m == 0) {
// 		return 0;
// 	}
// 	if (dp[n][m] != -1)
// 		return dp[n][m];

// 	if (s[n-1] == t[m-1]) {
// 		return dp[n][m] = 1 + recurse(n-1, m-1);
// 	}
// 	return dp[n][m] = max(recurse(n-1, m), recurse(n, m-1));
// }

int main() {
	cin >> s >> t;
	int n = s.size(), m = t.size();
	// top-down:
	// memset(dp, -1, sizeof(dp));
	// cout << recurse(n, m) << endl;

	// iterative: bottom up dp
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (s[i-1] == t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else 
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

		}
	}

	cout << dp[n][m] << '\n';

	for (int i = 0; i <= n; i++) {
		for (int j=0; j<=m; j++) {
			cerr << dp[i][j] << ' ';
		}
		cerr << '\n';
	}

	int i = n, j = m;
	string lcs = "";
	while(i > 0 && j > 0) {
		if (s[i-1] == t[j-1]) {
			lcs = s[i-1] + lcs;
			i--;
			j--;
			continue;
		} 
		if (dp[i-1][j] > dp[i][j-1]) {
			i--;
		} else {
			j--;
		}	
	}

	cout << lcs << '\n';

	return 0;
}