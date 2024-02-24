#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

const int N = 2e5 + 5;
// given a floor of area 2 * N we need to find the number of ways to tile the area with tiles 
// of dimensions equal 2 * 1 

// Variation : The floor can be of dimensions 3 * N

int n;
int dp[N];

int32_t main() 
{
  	cin >> n;
  	dp[0] = 1;
  	for(int i = 4; i <= n; i++)
  	{
  		dp[i] = dp[i-1] + (i >= 2 ? dp[i-2] : 0);
  	}
  	cout << dp[n] << endl;
	return 0;
}