#include <bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5;

template<class T>
class FenwickTree {
  private:
    int n;
    vector<T> tree;  // stores the BIT
  public:

    FenwickTree(int _n) {
      n = _n;
      tree.assign(n, 0);
    }

    FenwickTree(vector<T> data) : FenwickTree(data.size()) {
      for (int i = 1; i <= data.size(); ++i) {
        increase(i, data[i]);
      }
    }

    // update data[k] to data[k] + val;
    void increase(int k, T val) { 
      for (; k <= n; k += (k & -k)) {
        tree[k] += val;
      }
    }

    // update data[k] to val;
    void update(int k, T val) {
      increase(k, val - tree[k]);
    }

    T sum(int k) {
      T _sum = 0;
      for (; k > 0; k -= (k & -k)) {
        _sum += tree[k];
      }
      return _sum;
    }

    T sum (int a, int b) {
      return sum(b) - sum(a-1);
    }

};

int solve()
{
  vector<int> v = {0,1,2,3,4,5};
  FenwickTree<int> bit(v);
  cout << bit.sum(1, 5) << endl;
  bit.increase(3, 2);
  cout << bit.sum(1, 5) << endl;
  bit.update(3, 3);
  cout << bit.sum(1, 5) << endl;
  return 0;
}
