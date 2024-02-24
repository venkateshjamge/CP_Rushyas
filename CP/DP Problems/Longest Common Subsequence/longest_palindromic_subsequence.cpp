#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	// lps = lcs(s, t) 
	// i.e lps = lcs(s, reverse(s));
	return 0;
}