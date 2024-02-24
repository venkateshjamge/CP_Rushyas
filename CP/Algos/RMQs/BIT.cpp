#include <bits/stdc++.h>
using namespace std;

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{	
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		for(int i = idx; i <= N; i += i & -i)
		{
			bit[i] += val;
		}
	}

	void psum(int idx)
	{
		int ans = 0;
		for(int i = idx; i > 0; i -= i & -i)
		{
			ans += bit[i];
		}
		return ans;
	}

	void rsum(int l, int r)
	{
		return psum(r) - psum(l - 1);
	}

	// Returns the minimum index for which psum >= val
	void search(int val)
	{	
		int L = 1, R = N;
		int ans = -1;
		while(L <= R)
		{
			int mi = L + (R - L) / 2;
			int pref = psum[mi];
			if(pref >= val)
			{
				ans = mi;
				R = mi - 1;
			}
			else
			{
				L = mi + 1;
			}
		}
		return ans;
	}
};