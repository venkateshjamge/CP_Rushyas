#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

int n;
string s;
int cache[105][105][2];

// 3D dp is required for this problem
// k will always be the index of operator and not the T / F
int recurse(int i, int j, bool B) 
{
	if (i > j) 
		return cache[i][j][B] = 0;
	if (i == j)
		if (B)
			return cache[i][j][B] = (int) (s[i] == 'T');
		else 
			return cache[i][j][B] = (int) (s[i] == 'F');

	if (cache[i][j][B] != -1)
		return cache[i][j][B]; 
	int ways = 0;
	for (int k = i+1; k < j; k += 2)
	{
		if (s[k] == '&') 
		{
			if (B)  
				ways += (recurse(i, k-1, true) * recurse(k+1, j, true));
		    else
		    {
		    	ways += (recurse(i, k-1, true) * recurse(k+1, j, false));
		    	ways += (recurse(i, k-1, false) * recurse(k+1, j, true));
		    	ways += (recurse(i, k-1, false) * recurse(k+1, j, false));
		    } 
		}
		    	
		else if (s[k] == '|') 
		{
			if (B)
			{
				ways += (recurse(i, k-1, true) * recurse(k+1, j, true));
				ways += (recurse(i, k-1, true) * recurse(k+1, j, false));
				ways += (recurse(i, k-1, false) * recurse(k+1, j, true));
			} 
			else
				ways += (recurse(i, k-1, false) * recurse(k+1, j, false));
		} 
		else 
		{
			if (B)
			{
				ways += (recurse(i, k-1, true) * recurse(k+1, j, false));
				ways += (recurse(i, k-1, false) * recurse(k+1, j, true));
			} 
			else 
			{
				ways += (recurse(i, k-1, true) * recurse(k+1, j, true));
				ways += (recurse(i, k-1, false) * recurse(k+1, j, false));
			}
		}
	}
	return cache[i][j][B] = ways;
}

int32_t main() 
{
	IOS;
	cin >> s;
	n = s.size();
	memset(cache, -1, sizeof(cache));
	cout << recurse(0, n-1, true) << endl;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		cerr << cache[i][j] << ' ';
	// 	cerr << endl;
	// }
	return 0;
}