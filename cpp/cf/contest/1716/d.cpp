#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> dp(n + 1), ans(n + 1);
    dp[0] = 1;
    for (int mn = 0; mn + k <= n; mn += k++) {
        std::vector<int> sum(k);
        for (int i = mn; i <= n; ++i) {
            int cur = dp[i];
            dp[i] = sum[i % k];
            (sum[i % k] += cur) %= mod;
            (ans[i] += dp[i]) %= mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }
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
