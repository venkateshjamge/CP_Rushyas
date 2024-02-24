#include <bits/stdc++.h>
using namespace std;

const int N = 1 + 5;


// constuct with a given size (1 : n)
class DSU {
private:
    int n, components;
    vector<int> parent;
    vector<int> ranks;
public: 
    DSU(int _n) {
        components = _n;
        n = _n+1;
        ranks.assign(n, 0);
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    // returns the repr. of subset containing x
    int find(int x) {
        if (parent[x] == x) 
            return x;
        return parent[x] = find(parent[x]);  
    }

    // unites the subsets according to the ranks of repr. of subsets
    void unite(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);
        if (par_x != par_y)
        {
            if (ranks[par_x] < ranks[par_y])
                swap(par_x, par_y);
            parent[par_y] = parent[par_x];
            if (ranks[par_x] == ranks[par_y])
                ranks[par_x]++;
            components--;
        }
    }

    // returns true if two elements in the same subsets
    bool inSameSubset(int x, int y) {
        return find(x) == find(y);
    }

    // returns the number of components
    int get_components() {
        return components;
    }

    // debug the parent and ranks vectors
    // void debug() {
    //     debug(parent);
    //     debug(ranks);
    // }
};

int main() {
  DSU dsu(5);
  // dsu.debug();
  dsu.unite(1, 3);
  dsu.unite(3, 5);
  cout << "components now: " << dsu.get_components() << endl;
  cout << dsu.inSameSubset(1, 5) << endl;
  cout << dsu.inSameSubset(2, 4) << endl;
  dsu.unite(2, 4);
  cout << dsu.inSameSubset(2, 4) << endl;
  cout << dsu.get_components() << endl;
  return 0;
}
