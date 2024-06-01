#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int maxl = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        maxl = std::max(maxl, a[i]);
    }
    std::vector<std::vector<int>> dp(n + 1,
                                     std::vector<int>(2 * maxl + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int left = 0; left <= 2 * maxl; left++) {
            if (dp[i][left] == 1e9) {
                continue;
            }
            dp[i + 1][std::max(left - a[i], 0)] = std::min(
                dp[i + 1][std::max(left - a[i], 0)], dp[i][left] + a[i]);
            if (left + a[i] < dp[i + 1].size()) {
                dp[i + 1][left + a[i]] = std::min(
                    dp[i + 1][left + a[i]], std::max(dp[i][left] - a[i], 0));
            }
        }
    }

    int ans = 2 * maxl + 1;
    for (int left = 0; left <= 2 * maxl; left++) {
        ans = std::min(ans, left + dp[n][left]);
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
