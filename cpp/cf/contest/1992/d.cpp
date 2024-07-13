#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string s;
    std::cin >> s;

    std::vector<int> dp(n + 2, -1);
    dp[0] = k;
    for (int i = 1; i <= n + 1; i++) {
        if (i != n + 1 && s[i - 1] == 'c') {
            continue;
        }
        for (int t = 1; t <= m; t++) {
            if (i - t >= 0 && (i - t == 0 || s[i - t - 1] == 'L')) {
                dp[i] = std::max(dp[i], dp[i - t]);
            }
        }
        if (i > 1 && s[i - 2] == 'W') {
            dp[i] = std::max(dp[i], dp[i -  1] - 1);
        }
    }
    std::cout << (dp[n + 1] >= 0 ? "Yes" : "No") << '\n';
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
