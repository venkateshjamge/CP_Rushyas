#include <bits/stdc++.h>
using namespace std;

// This is the advanced version of the insertion sort 
// and it reduces the number of swaps required

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// start with gap = n / 2;
	for (int g = n / 2; g > 0; g /= 2) {
		// start from the gap and then increase it by +1 
		for (int i = g; i < n; i++) {
			int j = i;
			// do while the before element j - g >= 0 (valid index);
			while (j - g >= 0 && a[j-g] > a[j]) {
				swap(a[j - g], a[j]);
				j -= g;
			}
		}
	}
	for (auto x : a) cout << x << " ";
	cout << endl;
}