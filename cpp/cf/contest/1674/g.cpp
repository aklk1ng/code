#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> dp(n, -1), in(n), out(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> v >> u;
        u--, v--;
        g[v].push_back(u);
        in[u]++;
        out[v]++;
    }

    auto cal = [&](auto self, int v) {
        if (dp[v] != -1) {
            return dp[v];
        }
        if (in[v] >= 2 && out[v] >= 2) {
            dp[v] = 1;
            for (auto &u : g[v]) {
                dp[v] = std::max(dp[v], self(self, u) + 1);
            }
        } else if (in[v] >= 2) {
            dp[v] = 1;
        } else {
            dp[v] = INT_MIN;
        }
        return dp[v];
    };
    int ans = 1;
    for (int v = 0; v < n; v++) {
        if (out[v] >= 2) {
            for (auto &u : g[v]) {
                ans = std::max(ans, cal(cal, u) + 1);
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
