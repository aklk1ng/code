#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int m, x;
    std::cin >> m >> x;

    int s = 0;

    std::vector<ll> dp{-1};
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        int c, h;
        std::cin >> c >> h;

        s += h;
        dp.resize(s + 1, -1);

        for (int j = s; j >= h; j--) {
            if (dp[j - h] >= c) {
                dp[j] = std::max(dp[j], dp[j - h] - c);
            }
        }
        for (int j = 0; j <= s; j++) {
            if (dp[j] >= 0) {
                dp[j] += x;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= s; i++) {
        if (dp[i] >= 0) {
            ans = i;
        }
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
