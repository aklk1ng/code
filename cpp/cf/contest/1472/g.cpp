#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> cal(std::vector<std::vector<int>> const &g) {
    std::vector<int> dist(g.size(), -1);
    dist[1] = 0;
    std::queue<int> pq;
    pq.push(1);
    while (!pq.empty()) {
        int u = pq.front();
        pq.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pq.push(v);
            }
        }
    }

    return dist;
}

void dfs(int u, std::vector<std::vector<int>> const &g,
         std::vector<int> const &dist, std::vector<int> &dp,
         std::vector<bool> &used) {
    used[u] = true;
    dp[u] = dist[u];
    for (int v : g[u]) {
        if (!used[v] && dist[u] < dist[v]) {
            dfs(v, g, dist, dp, used);
        }

        if (dist[u] < dist[v]) {
            dp[u] = std::min(dp[u], dp[v]);
        } else {
            dp[u] = std::min(dp[u], dist[v]);
        }
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }

    std::vector<int> dist = cal(g);
    std::vector<int> dp(n + 1);
    std::vector<bool> used(n + 1);
    dfs(1, g, dist, dp, used);
    for (int i = 1; i <= n; i++) {
        std::cout << dp[i] << " ";
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
