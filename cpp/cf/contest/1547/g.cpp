#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<std::vector<int>> g;
std::set<int> s[2];

void dfs(int u, std::vector<int> &color, bool flag) {
    color[u] = 1;
    for (int v : g[u]) {
        if (color[v] == 0) {
            dfs(v, color, flag);
        } else if (flag) {
            s[color[v] - 1].insert(v);
        }
    }
    color[u] = 2;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    g.assign(n, std::vector<int>());
    for (int i = 0; i < 2; i++) {
        s[i] = std::set<int>();
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    std::vector<int> color(n);
    dfs(0, color, true);
    std::vector c(2, std::vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (auto &u : s[i]) {
            dfs(u, c[i], false);
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        if (color[i]) {
            ans = 1;
            if (c[0][i]) {
                ans = -1;
            } else if (c[1][i]) {
                ans = 2;
            }
        }
        std::cout << ans << " \n"[i == n - 1];
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
