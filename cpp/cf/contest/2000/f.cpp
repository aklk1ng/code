#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }

    std::vector dp(n + 1, std::vector<int>(k + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = b[i];
        int xy = x + y;
        int cost = 0;
        for (int j = 0; j <= xy; ++j) {
            for (int j1 = 0; j1 + j <= k; ++j1) {
                dp[i + 1][j1 + j] =
                    std::min(dp[i + 1][j1 + j], dp[i][j1] + cost);
            }
            if (j < xy) {
                if (x >= y) {
                    x--; cost += y;
                } else {
                    y--; cost += x;
                }
            }
        }
    }
    std::cout << (dp[n][k] == 1e9 ? -1 : dp[n][k]) << '\n';
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
