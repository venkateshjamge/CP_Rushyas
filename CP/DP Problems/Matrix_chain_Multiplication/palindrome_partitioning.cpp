#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

int n;
string s;
int cache[105][105];

bool isPal(int i, int j) {
	while(i < j && s[i] == s[j]) ++i, --j;
	return (i == j);
}

int recurse(int i, int j) {
	if (i >= j) 
		return cache[i][j] = 0;
	if (cache[i][j] != -1) {
		return cache[i][j];
	}
	// isPal call must be below the call to the cache check
	if (isPal(i, j))
		return cache[i][j] = 0;

	// this is imp : k < j as the 2nd partition is [k+1, j]
	int ans = 9e18;
	for (int k = i; k < j; k++) {
		int curpart = 1 + recurse(i, k) + recurse(k+1, j);
		ans = min(ans, curpart);
	}
	return cache[i][j] = ans;
}


int32_t main() 
{
	IOS;
	cin >> s;
	n = s.size();
	memset(cache, -1, sizeof(cache));
	cout << recurse(0, n-1) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cerr << cache[i][j] << ' ';
		cerr << endl;
	}
	return 0;
}