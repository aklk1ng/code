#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n + 1);
    std::vector<int> mi(2);
    mi.assign(2, 1e9);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (!a[i]) {
            dp[i] = std::min(dp[i], dp[i - 1]);
        }
        if (a[i] <= 2) {
            dp[i] = std::min(dp[i], i + mi[1 - i % 2]);
        }
        if (a[i] <= 2) {
           mi[i % 2] = std::min(mi[i % 2], dp[i - 1] - i);
        } else if (a[i] > 4) {
            mi[0] = mi[1] = 1e9;
        }
    }
    std::cout << dp[n] << '\n';
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
