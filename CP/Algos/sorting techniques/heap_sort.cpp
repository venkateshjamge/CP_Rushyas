#include <bits/stdc++.h>
using namespace std;

void heapify(int idx, int n, vector<int>& a) {
	int left = 2*idx+1;
	int right = 2*idx+2;
	int largest=idx;
	if(left < n && a[left]>a[largest]){
		largest=left;
	}
	if(right < n && a[right]>a[largest]){
		largest=right;
	}
	if(largest!=idx){
		swap(a[idx],a[largest]);
		heapify(largest,n,a);
	}
}

void heap_sort(int n, vector<int>& a) {
	// build heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(i, n, a);
	}
	for(auto x:a) cout<<x<<" "; cout<<endl;
	// extract elements one by one now and again call the heapify
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		heapify(0, i, a);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	heap_sort(n, a);
	for (auto x : a) cout << x << " ";
	cout << "\n";
}

// True love