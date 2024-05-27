#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> ord;
std::vector<int> used;
std::vector<std::vector<int>> g;

void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    ord.push_back(v);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    g = std::vector<std::vector<int>>(n);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int t, x, y;
        std::cin >> t >> x >> y;
        --x, --y;
        if (t == 1) {
            g[x].push_back(y);
        }
        edges.push_back({x, y});
    }

    ord.clear();
    used = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    std::vector<int> pos(n);
    std::reverse(ord.begin(), ord.end());
    for (int i = 0; i < n; ++i) {
        pos[ord[i]] = i;
    }
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        for (auto j : g[i]) {
            if (pos[i] > pos[j]) {
                bad = true;
            }
        }
    }
    if (bad) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
        for (auto [x, y] : edges) {
            if (pos[x] < pos[y]) {
                std::cout << x + 1 << " " << y + 1 << '\n';
            } else {
                std::cout << y + 1 << " " << x + 1 << '\n';
            }
        }
    }
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
