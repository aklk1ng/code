#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> color(n, -1);
    std::deque<int> q;
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        color[--x] = 0;
        q.push_back(x);
    }
    color[0] = 1;
    q.push_back(0);
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto &u : g[v]) {
            if (color[u] == -1) {
                color[u] = color[v];
                q.push_back(u);
            }
        }
    }
    for (int v = 1; v < n; v++) {
        if (g[v].size() == 1 && color[v] == 1) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
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
