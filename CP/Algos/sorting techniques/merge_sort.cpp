#include <bits/stdc++.h>
using namespace std;

// function to merge all the sorted lists
void merge_lists(int s, int mid, int e, vector<int>& a) {
	vector<int> aa, bb;
	int idx = s;
	for (int i = s; i <= mid; i++) {
		aa.push_back(a[i]);
	}
	for (int i = mid + 1; i <= e; i++) {
		bb.push_back(a[i]);
	}
	int i = 0, j = 0;
	while (i < aa.size() && j < bb.size()) {
		if (aa[i] < bb[j]) {
			a[idx++] = aa[i++];
		} else {
			a[idx++] = bb[j++];
		}
	}
	while(i < aa.size()) {
		a[idx++] = aa[i++];		
	}
	while(j < bb.size()) {
		aa[idx++] = bb[j++];
	}
}

void merge_sort(int s, int e, vector<int>& a) {
	// important condition in quick as well as the merge sort algo
	if (e <= s) {
		return;
	}
	int mid = s + (e - s) / 2;
	merge_sort(s, mid, a);  // took the middle element in the first part of the element
	merge_sort(mid + 1, e, a); // skip the middle element here
	merge_lists(s, mid, e, a);  // now the individual lists are sorted need to merge the lists
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(0, n - 1, a);
	for (auto x : a) cout << x << " ";
	cout << endl;
}