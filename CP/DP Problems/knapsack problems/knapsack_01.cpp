#include <bits/stdc++.h>
using namespace std;

int vals[200], wts[200];
int dp[200][200];


// int recurse(int n, int W)
// {
// 	if (n == 0 || W == 0)
// 		return dp[n][W] = 0;

// 	if (dp[n][W] != -1)
// 		return dp[n][W];

// 	if (W >= wts[n])
// 		return dp[n][W] = max(vals[n] + recurse(n-1, W - wts[n]), 
// 				   recurse(n-1, W));
	
// 	else return dp[n][W] = recurse(n-1, W);

// }

int main() {
	
	int n, W;
	cin >> n >> W;

	for (int i = 1; i <= n; i++)
		cin >> vals[i];
	for (int i = 1; i <= n; ++i)
		cin >> wts[i];

	// -1 setting is used for memoization
	// memset(dp, -1, sizeof(dp));
	// cout << recurse(n, w) << '\n'; 
	// bottom up approach: 

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++) 
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (wts[i] <= j)
				dp[i][j] = max(vals[i] + dp[i-1][j-wts[i]], dp[i-1][j]);
			
			else dp[i][j] = dp[i-1][j];

		}
	}
	
	cout << dp[n][W] << '\n';
}
 