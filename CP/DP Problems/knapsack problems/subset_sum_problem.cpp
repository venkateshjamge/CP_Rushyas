#include <bits/stdc++.h>
using namespace std;

int a[200005];
int dp[1000][1000];  


// Memoization solution 
// int recurse(int n, int t) {
// 	if (t == 0) return 1;
// 	if (n == 0 || t < 0) return -1;

// 	if (dp[n][t] == -1) return -1;
// 	else if (dp[n][t] == 1) return 1;

// 	if (t >= a[n]) 
// 		if (recurse(n-1, t) == 1 || recurse(n-1, t - a[n]) == 1) 
// 			return dp[n][t] = 1;		
// 		else 
// 			return dp[n][t] = -1;
// 	else 
// 		return dp[n][t] = recurse(n-1, t);
// }

int main() {
	
	memset(dp, 0, sizeof(dp));
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	// cout << (recurse(n, t) == 1 ? "Yes" : "No") << '\n';
	// tabulation kind of thing using the set :)

	unordered_set<int> s;
	s.insert(0);
	for (int i = 1; i <= n; i++) {
		unordered_set<int> ns = s;
		for (auto val : s) {
			ns.insert(val + a[i]);
		}
		s = ns;
	}
	cout << (s.find(t) != s.end() ? "Yes" : "No") << endl;  // O(1) : Time complexity;
	return 0;
}