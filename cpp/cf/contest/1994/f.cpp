#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> edge(m);
    std::vector black(n, std::vector<int>()), g(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--, v--;
        edge[i] = u ^ v;
        g[u].push_back(i);
        g[v].push_back(i);
        if (!c) {
            black[u].push_back(i);
            black[v].push_back(i);
        }
    }

    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        deg[i] = g[i].size() & 1;
    }
    std::vector<bool> del(m), used(n);
    auto dfs = [&](auto self, int u) -> void {
        used[u] = true;
        for (auto &id : black[u]) {
            int to = edge[id] ^ u;
            if (used[to]) {
                continue;
            }
            self(self, to);
            if (deg[to]) {
                del[id] = true;
                deg[to] ^= 1;
                deg[u] ^= 1;
            }
        }
    };
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        dfs(dfs, i);
        ok &= !deg[i];
    }
    if (!ok) {
        std::cout << "No\n";
        return;
    }
    auto cal = [&](auto self, int u) -> void {
        while (!g[u].empty()) {
            int id = g[u].back();
            g[u].pop_back();
            int to = edge[id] ^ u;
            if (del[id]) {
                continue;
            }
            del[id] = true;
            self(self, to);
        }
        std::cout << u + 1 << ' ';
    };
    std::cout << "Yes\n";
    std::cout << m - std::accumulate(del.begin(), del.end(), 0) << '\n';
    cal(cal, 0);
    std::cout << '\n';
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
