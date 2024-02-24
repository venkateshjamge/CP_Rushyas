#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#define dbg(...)
#else
#include <algo/dbg.h>  
#endif

#define i64 long long
#define nl '\n'

template<class T>
class SegmentTree {
private:
    static const int MAX = 4e5 + 5;
    int n;
    std::vector<T> Info;
    std::vector<T> Seg;
public:
    SegmentTree() : n(0) {}

    T apply(T a, T b) {
        // return a + b;            // sum - SegTree
        // return std::min(a, b);   // min - SegTree
        // return std::max(a, b);   // max - SegTree
    }

    void init(int n, std::vector<T> info) {
        this->n = n;
        this->Info = info;
        Seg.resize(4 << std::__lg(n));
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                Seg[p] = Info[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            Seg[p] = apply(Seg[2 * p], Seg[2 * p + 1]);
        };
        build(1, 1, n);
    }

    void modify(int p, int l, int r, int q, T v) {
        if (q < l || q > r) {
            return;
        }
        if (l == r) {
            Seg[p] += v;
            Info[q] += v;
            return;
        }
        int m = (l + r) / 2;
        if (q <= m) {
            modify(2 * p, l, m, q, v);
        } else {
            modify(2 * p + 1, m + 1, r, q, v);
        }
        Seg[p] = apply(Seg[2 * p], Seg[2 * p + 1]);
    }
    
    T query(int p, int l, int r, int x, int y) {
        if (y < l || x > r) {
            // return 0;    // apply(a, b) => a + b;
            // return 1e9;  // apply(a, b) => std::min(a, b);
            // return -1e9; // apply(a, b) => std::max(a, b);
        }
        if (x <= l && r <= y) {
            return Seg[p];
        }
        int m = (l + r) / 2;
        return apply(query(2 * p, l, m, x, y), query(2 * p + 1, m + 1, r, x, y)); 
    }

    void modify(int q, T v) {
        modify(1, 1, n, q, v);
    }

    T query(int x, int y) {
        return query(1, 1, n, x, y);
    }
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}