#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (auto x : a) cout << x << ' '; 
	cout << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j+ 1])
				swap(a[j], a[j + 1]);
		}
	}
	for (auto x : a) cout << x << " ";
	cout << endl;
}