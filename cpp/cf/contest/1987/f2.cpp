#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector dp(n + 1, std::vector<int>(n + 1, INT_MAX));
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int le = 1; le <= n; le++) {
        for (int l = 0; l + le <= n; l++) {
            if (a[l] % 2 != (l + 1) % 2) {
                continue;
            }
            if (a[l] > l + 1) {
                continue;
            }
            int v = (l + 1 - a[l]) / 2;

            int r = l + le;
            for (int m = l + 1; m < r; m += 2) {
                if (dp[l + 1][m] <= v) {
                    int new_val = std::max(v, dp[m + 1][r] - (m - l + 1) / 2);
                    dp[l][r] = std::min(dp[l][r], new_val);
                }
            }
        }
    }

    std::vector<int> dp2(n + 1);
    for (int i = 0; i < n; i++) {
        dp2[i + 1] = dp2[i];

        for (int j = 0; j < i; j++) {
            if (dp[j][i + 1] <= dp2[j]) {
                dp2[i + 1] = std::max(dp2[i + 1], dp2[j] + (i - j + 1) / 2);
            }
        }
    }
    std::cout << dp2[n] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
