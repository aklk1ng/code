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
    int n;
    std::cin >> n;
    int k;
    std::cin >> k;

    std::vector dp(n + 1, std::vector<int>(k + 1));
    dp[0][0] = 1;
    std::vector<int> sum(k + 1);
    sum[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int &d = dp[i + 1][std::min(j + 1, k)];
            d = add(d, sum[j]);
            if (i >= 2 && i != n - 1) {
                d = add(d, -dp[i - 1][j]);
            }
        }
        for (int j = 0; j <= k; j++) {
            sum[j] = add(sum[j], dp[i + 1][j]);
        }
    }
    std::cout << dp[n][k] << '\n';
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
