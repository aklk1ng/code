#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n), dp(n);
    auto check = [&](int med) -> bool {
        for (int i = 0; i < n; i++) {
            if (a[i] >= med) {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }

        dp[0] = b[0];
        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                dp[i] = std::max(dp[i - k], b[i]);
            } else {
                dp[i] = dp[i - 1] + b[i];
                if (i > k) {
                    dp[i] = std::max(dp[i], dp[i - k]);
                }
            }
        }

        return dp[n - 1] > 0;
    };
    int l = 1, h = 1e9;
    while (l <= h) {
        int mid = (l + h) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    std::cout << h << '\n';
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
