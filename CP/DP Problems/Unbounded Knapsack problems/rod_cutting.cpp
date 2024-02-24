#include <bits/stdc++.h>
using namespace std;

int n;
int price[105];
int dp[105];
// int dp[105][105];

int recurse(int len) {
	if (len == 0) 
		return dp[len] = 0;

	if (dp[len] != -1) 
		return dp[len];

	int mx = 0;

	for (int i = len; i >= 1; --i) {
		// if (i > len) continue; // not needed when i starts from len and not n => len >=0 for all calls
		mx = max(mx, price[i] + recurse(len - i));
	}

	return dp[len] = mx;
}

// 2D dp like other unbounded knapsack problems
// int recurse(int idx, int len) 
// {
// 	if (len == 0 || idx == 0) return 0;
// 	else if (dp[idx][len] != -1) return dp[idx][len];
// 	dp[idx][len] = recurse(idx - 1 ,len);
// 	if (idx <= len){
// 		dp[idx][len] = max(dp[idx][len], price[idx] + recurse(idx, len-idx));
// 	}
// 	return dp[idx][len];
// }

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> price[i];

	memset(dp, -1, sizeof(dp));

	// cout << "ans: " << recurse(n, n) << '\n';
	cout << "ans: " << recurse(n) << '\n';
	return 0;
}