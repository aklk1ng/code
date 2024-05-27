#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::set<int>> g;
std::vector<std::set<int>> leaves;

struct comp {
    bool operator()(int a, int b) const {
        if (leaves[a].size() == leaves[b].size()) {
            return a < b;
        }
        return leaves[a].size() > leaves[b].size();
    }
};

void solve() {

    int n, k, ans = 0;
    std::cin >> n >> k;
    g = leaves = std::vector<std::set<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        g[x].insert(y);
        g[y].insert(x);
    }

    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            leaves[*g[i].begin()].insert(i);
        }
    }
    std::set<int, comp> st;
    for (int i = 0; i < n; ++i) {
        st.insert(i);
    }
    while (true) {
        int v = *st.begin();
        if (int(leaves[v].size()) < k) {
            break;
        }
        for (int i = 0; i < k; ++i) {
            int leaf = *leaves[v].begin();
            g[leaf].erase(v);
            g[v].erase(leaf);
            st.erase(v);
            st.erase(leaf);
            leaves[v].erase(leaf);
            if (leaves[leaf].count(v)) {
                leaves[leaf].erase(v);
            }
            if (g[v].size() == 1) {
                int to = *g[v].begin();
                st.erase(to);
                leaves[to].insert(v);
                st.insert(to);
            }
            st.insert(v);
            st.insert(leaf);
        }
        ans += 1;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
