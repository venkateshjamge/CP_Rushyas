#include <bits/stdc++.h>
using namespace std;

string s, t;

int dp[105][105];

// if there is no replace operation in this q. then the answer is : |A| + |B| - 2 * |LCS(A, B)|;


int main() {
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = (i + j);
				continue;
			}
			if (s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
			}
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= m; j++) {
	// 		cerr << dp[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }

	cout << dp[n][m] << '\n';
	return 0;
}