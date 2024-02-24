#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[105][105];

int main() {
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (s[i-1] == t[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cerr << dp[i][j] << ' '; 
		}
		cerr << '\n';
	}

	cout << dp[n][m] << '\n';

	int i = n, j = m;
	string lcs = "";
	while (i > 0 && j > 0) {
		if (s[i-1] == t[j-1]) {
			lcs = s[i-1] + lcs;
			--i, --j;
			continue;
		}
		if (dp[i-1][j] > dp[i][j-1]) --i;   // for scs here to is a push_back()
		else --j;
	}

	cout << lcs << '\n';

	int idx = 0;
	i = 0, j = 0;
	string scs = "";
	while(1) {
		if (i >= n && j >= m) break;
		if (i < n && j >= m) {
			scs += s[i++];
		} else if (i >= n && j < m) {
			scs += t[j++];
		} else {
			while(i < n && (idx >= lcs.size() || (idx < lcs.size() && s[i] != lcs[idx]))) scs += s[i++];
			while(j < m && (idx >= lcs.size() || (idx < lcs.size() && t[j] != lcs[idx]))) scs += t[j++];
		 	if (idx < lcs.size()) {
				scs += lcs[idx++];
				++i; ++j;
			}
		}
	}

	cout << scs << '\n';


	// method 2 : like finding the lcs but just push_back() all the boxes where you land on!
	i = n, j = m;
	string scs2 = "";
	while(i > 0 && j > 0) {
		scs2 = 
	}
	return 0;
}