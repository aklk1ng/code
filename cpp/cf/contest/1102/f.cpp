#include <bits/stdc++.h>
#define ll long long
const int INF = 1e9;

int n, m;
std::vector<std::vector<int>> mn1, mn2;
int dp[1 << 18][18];

int cal(int mask, int v) {
    if (dp[mask][v] != -1) {
        return dp[mask][v];
    }
    dp[mask][v] = 0;
    for (int u = 0; u < n; u++) {
        if (u != v && ((mask >> u) & 1)) {
            dp[mask][v] = std::max(
                dp[mask][v], std::min(mn1[u][v], cal(mask ^ (1 << v), u)));
        }
    }
    return dp[mask][v];
}

void solve() {
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    mn1.assign(n, std::vector<int>(n, 0));
    mn2.assign(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = INF;
            for (int k = 0; k < m; k++) {
                val = std::min(val, abs(a[i][k] - a[j][k]));
            }
            mn1[i][j] = val;
            val = INF;
            for (int k = 0; k < m - 1; k++) {
                val = std::min(val, abs(a[i][k] - a[j][k + 1]));
            }
            mn2[i][j] = val;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(dp, -1, sizeof(dp));
        for (int j = 0; j < n; j++) {
            dp[1 << j][j] = (j == i ? INF : 0);
        }
        for (int j = 0; j < n; j++) {
            ans = std::max(ans, std::min(mn2[j][i], cal((1 << n) - 1, j)));
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
