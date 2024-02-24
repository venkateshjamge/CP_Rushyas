#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	ll cnt[2] = {0};
	for (auto x : a)
		cnt[x % 2]++;
	if(a[0] == 1) {
		cout << "YES" << nl;
	}
	else {
		cout << "NO" << nl;
	}
}

int main() {
	ll t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}