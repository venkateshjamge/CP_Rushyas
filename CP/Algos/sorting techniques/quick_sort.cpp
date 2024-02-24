#include <bits/stdc++.h>
using namespace std;

int partition(int s, int e, vector<int>& a) {
	// take the last element as the pivot element to partition the array
	int p = a[e];
	int correct_pos = s - 1;
	for (int j = s; j < e; j++) {
		// when the current element is less than the pivot
		if (a[j] < p) {
			correct_pos++;
			swap(a[j], a[correct_pos]);
		}
	}
	correct_pos++;
	swap(a[e], a[correct_pos]);
	return correct_pos;
}

void quick_sort(int s, int e, vector<int>& a) {
	if (e <= s)
		return;
	int idx = partition(s, e, a);
	// for (auto x : a) cout << x << " ";
	// cout << endl;
	quick_sort(s, idx - 1, a);
	quick_sort(idx + 1, e, a);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	quick_sort(0, n - 1, a);
	for (auto x : a) cout << x << " ";
	cout << endl;
}