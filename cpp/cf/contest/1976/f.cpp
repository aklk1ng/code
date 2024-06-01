#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
std::vector<int> h;
std::vector<std::vector<int>> g;

void dfs(int v, int p = -1) {
    for (int u : g[v])
        if (u != p) {
            dfs(u, v);
            h[v] = std::max(h[v], h[u] + 1);
        }
}

void solve() {
    int n;
    std::cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        std::cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    h.assign(n, 0);
    dfs(0);
    std::set<std::pair<int, int>> cur;
    for (int i = 0; i < n; i++) {
        cur.insert({h[i], i});
    }
    std::vector<int> ans;
    int tmp = n;
    while (!cur.empty()) {
        int v = cur.rbegin()->second;
        while (v != -1) {
            --tmp;
            cur.erase({h[v], v});
            int pv = -1;
            for (int u : g[v])
                if (h[u] == h[v] - 1) {
                    pv = u;
                    break;
                }
            v = pv;
        }
        ans.push_back(tmp);
    }
    for (int i = 0; i < int(ans.size()); i += 2) {
        std::cout << ans[i] << ' ';
    }
    for (int i = (int(ans.size()) + 1) / 2; i < n - 1; ++i) {
        std::cout << 0 << ' ';
    }
    std::cout << '\n';
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
