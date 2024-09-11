#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int t0, t1, t2;
    std::cin >> t0 >> t1 >> t2;
    std::vector<std::vector<std::vector<int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, l1, l2;
        std::cin >> u >> v >> l1 >> l2;
        u--, v--;
        g[u].push_back({v, l1, l2});
        g[v].push_back({u, l1, l2});
    }

    std::set<std::pair<int, int>> prq;
    prq.insert({t0, n - 1});
    for (int i = 0; i + 1 < n; ++i) {
        prq.insert({-1e9, i});
    }
    std::vector<int> dist(n, -1e9);
    dist[n - 1] = t0;
    while (!prq.empty()) {
        auto p = *prq.rbegin();
        prq.erase(p);
        int d = p.first, u = p.second;
        for (auto e : g[u]) {
            int v = e[0], l1 = e[1], l2 = e[2];
            int d1 = (d - l1 >= t2 || d <= t1) ? d - l1 : d - l2;
            if (d1 == d - l2) {
                d1 = std::max(d1, t1 - l1);
            }
            if (dist[v] < d1) {
                prq.erase({dist[v], v});
                dist[v] = d1;
                prq.insert({d1, v});
            }
        }
    }
    std::cout << (dist[0] >= 0 ? dist[0] : -1) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
