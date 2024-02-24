#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s; transform(s.begin(), s.end(), s.begin(), [](char c){ return c == '0' ? '(' : ')'; });
        int n = s.size();
        int le = 0, ri = n / 4;
        while(le <= ri){
            int mi =(le + ri) / 2;
            bool ok = false;
            // greedily takes 2 * mi left 0 and 2 * mi right 1
            vector<int> pos;
            for(int i = 0, cur = 0; i < n; i++){
                if(s[i] == '(' && cur < 2 * mi){
                    pos.push_back(i);
                    cur++;
                }
            }
            for(int i = n - 1, cur = 0; i >= 0; i--){
                if(s[i] == ')' && cur < 2 * mi){
                    pos.push_back(i);
                    cur++;
                }
            }
            if(pos.size() == 4 * mi){
                sort(pos.begin(), pos.end());
                string cur;
                for(int ind : pos){
                    cur += s[ind];
                }
                auto build = [](string &&s){
                    // one outer layer for ease of implementation in solve
                    vector<vector<int>> adj = {{}};
                    vector<int> sz = {1}, stk;
                    int cnt = 1;
                    adj.push_back({});
                    for(char &c : s){
                        if(c == '('){
                            stk.push_back(cnt++);
                            adj.push_back({});
                            sz.push_back(1);
                        } else {
                            if(stk.empty()){
                                adj.clear(); sz.clear();
                                return make_pair(adj, sz);
                            } else {
                                int top = stk.back(); stk.pop_back();
                                int par = stk.empty() ? 0 : stk.back();
                                adj[par].push_back(top);
                                sz[par] += sz[top];
                            }
                        }
                    }
                    return make_pair(adj, sz);
                };
                auto [adj, sz] = build(move(cur));
                if(!adj.empty()){
                    function<bool(int, int)> solve = [&adj = adj, &sz = sz, &solve](int u, int off){
                        int sz_of_children = sz[u] - 1;
                        if(adj[u].empty()){
                            return true;
                        }
                        for(int v : adj[u]){
                            if(off -(sz_of_children - sz[v]) >= 0 && solve(v, off -(sz_of_children - sz[v]) + 1)){
                                return true;
                            }
                        }
                        return false;
                    };
                    // off = moves advantage alice have over bob
                    ok = solve(0, 1);
                }
            }
            if(ok){
                le = mi + 1;
            } else {
                ri = mi - 1;
            }
        }
        cout << ri << '\n';
    }
}
