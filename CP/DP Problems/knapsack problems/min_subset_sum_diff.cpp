#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int dp[105][105];

int recurse(int n, int t) {
	if (t == 0)
		return dp[n][t] = 1;
	if (n == 0)
		return dp[n][t] = 0;
	
	return dp[n][t] = recurse(n-1, t) + (a[n] <= t ? recurse(n-1, t - a[n]) : 0);

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	memset(dp, -1, sizeof(dp));
	int range = accumulate(a+1, a+n+1, 0);
	cerr << range << '\n';
	int diff = 1000000;
	
	for (int s1 = 0; s1 <= range; s1++) {
		if (recurse(n, s1) > 0) {
			int s2 = range - s1;
			diff = min(diff, abs(s2 - s1));
		}
	}

	// to find the count of given diff : 

	// s1 - s2 = diff
	// s1 + s2 = range
	// ------------------
	// s1 = (diff + range) / 2;
	
	// just find out the count of sum = cnt(s1) where s1 = (diff + range) / 2;
	return 0;
}