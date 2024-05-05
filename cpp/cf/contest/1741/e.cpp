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

    std::vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        if (i + a[i] <= n && dp[i - 1]) {
            dp[i + a[i]] = true;
        }
        if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) {
            dp[i] = true;
        }
    }
    std::cout << (dp[n] ? "YES" : "NO") << '\n';
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
