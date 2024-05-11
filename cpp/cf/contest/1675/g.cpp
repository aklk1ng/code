#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), p(1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            p.emplace_back(i);
            int c = p.size();
            p[c - 1] += p[c - 2];
        }
        if (i > 0) {
            a[i] += a[i - 1];
        }
    }
    std::vector dp(n, std::vector<std::vector<int>>(
                          m + 1, std::vector<int>(m + 1, 1e9 + 7)));
    for (int j = 0; j <= m; j++) {
        if (a[0] >= j) {
            dp[0][j][j] = a[0] - j;
        } else {
            dp[0][j][j] = p[j];
        }
    }
    for (int j = m - 1; j >= 0; j--) {
        for (int k = j; k <= m; k++) {
            dp[0][j][k] = std::min(dp[0][j][k], dp[0][j + 1][k]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = j; k <= m; k++) {
                int add = 0;
                if (a[i] >= k) {
                    add = a[i] - k;
                } else {
                    int len = std::min(j, k - a[i]);
                    add = p[k] - p[k - len] - i * len;
                }
                dp[i][j][k] = dp[i - 1][j][k - j] + add;
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            for (int k = (i + 1) * j; k <= m; k++) {
                dp[i][j][k] = std::min(dp[i][j][k], dp[i][j + 1][k]);
            }
        }
    }
    std::cout << dp[n - 1][0][m] << '\n';
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
