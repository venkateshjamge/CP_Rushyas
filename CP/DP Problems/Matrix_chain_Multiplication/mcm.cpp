#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

int n;
int a[105];
int cache[105][105];

int recurse(int i, int j) {
	if (i >= j) 
		return 0;
	if(cache[i][j] != -1)
		return cache[i][j];

	int ans = 9e18;
	for (int k = i; k < j; k += 1) {
		int curcost = recurse(i, k) + recurse(k+1, j) + a[i-1] * a[k] * a[j];
		debug(i, j, k, curcost);
		ans = min(ans, curcost);
	}
	return cache[i][j] = ans;
}

int32_t main() 
{
	IOS;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cout << recurse(1, n-1) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cerr << cache[i][j] << ' ';
		cerr << endl;
	}
	return 0;
}