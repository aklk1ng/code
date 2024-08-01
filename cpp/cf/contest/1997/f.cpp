#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int x, int y) {
    x += y;
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
    return x;
}

int mul(int x, int y) { return (x * 1ll * y) % mod; }

void solve() {
    int n, x, m;
    std::cin >> n >> x >> m;

    std::vector<int> fib = {0, 1};
    for (int i = 2; i <= 30; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    int mx_sum = fib[x] * n;
    std::vector dp(mx_sum + 1, std::vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < mx_sum; j++) {
            for (int k = 0; k < n; k++) {
                if (j + fib[i] <= mx_sum) {
                    dp[j + fib[i]][k + 1] =
                        add(dp[j + fib[i]][k + 1], dp[j][k]);
                }
            }
        }
    }
    std::vector<int> cost(mx_sum + 1, 1e9);
    cost[0] = 0;
    for (int j = 1; j <= mx_sum; j++) {
        for (int i = 1; i <= 30; i++) {
            if (j >= fib[i]) {
                cost[j] = std::min(cost[j], cost[j - fib[i]] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= mx_sum; i++) {
        if (cost[i] == m) {
            ans = add(ans, dp[i][n]);
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
