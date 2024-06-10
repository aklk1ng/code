#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int n;
std::vector<std::vector<int>> adj;
std::vector<std::pair<int, int>> edges;
std::map<std::pair<int, int>, int> mp;

std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> from;
std::vector<int> miss;

void dfs(int e) {
    if (dp[0][e] >= 0 || dp[1][e] >= 0) {
        return;
    }
    int p = edges[e].first, v = edges[e].second;
    dp[0][e] = 0, dp[1][e] = 1;
    if (miss[v] < 0) {
        for (int u : adj[v]) {
            if (u == p) {
                continue;
            }
            int ne = mp[{v, u}];
            dfs(ne);
            from[0][v] += std::max(dp[1][ne], dp[0][ne]);
            from[1][v] += dp[0][ne];
        }
        miss[v] = p;
    }
    if (miss[v] != p && miss[v] != n) {
        int ne = mp[{v, miss[v]}];
        dfs(ne);
        from[0][v] += std::max(dp[1][ne], dp[0][ne]);
        from[1][v] += dp[0][ne];
        miss[v] = n;
    }
    if (miss[v] == n) {
        int nne = mp[{v, p}];
        dp[0][e] += from[0][v] - std::max(dp[1][nne], dp[0][nne]);
        dp[1][e] += from[1][v] - dp[0][nne];
    } else if (miss[v] == p) {
        dp[0][e] += from[0][v];
        dp[1][e] += from[1][v];
    }
}

void solve() {
    std::cin >> n;
    adj.clear(), edges.clear();
    adj.resize(n), edges.resize(2 * n - 2);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[2 * i] = {a, b};
        edges[2 * i + 1] = {b, a};
        mp[{a, b}] = 2 * i;
        mp[{b, a}] = 2 * i + 1;
    }

    from = std::vector<std::vector<int>>(2, std::vector<int>(n));
    miss = std::vector<int>(n, -1);
    dp = std::vector<std::vector<int>>(2, std::vector<int>(2 * n - 2, -1));
    for (int i = 0; i < 2 * n - 2; ++i) {
        dfs(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() != 1) {
            continue;
        }
        int e = mp[{i, adj[i][0]}];
        ans = std::max(ans, 1 + std::max(dp[0][e], dp[1][e]));
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
