#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    std::vector<int> dp(n + 1);
    int s = 0, j = -1;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = std::max(dp[i + 1], dp[i]);
        if (j < i) {
            j = i;
            s = 0;
        }
        while (j < n && s < l) {
            s += a[j++];
        }
        if (s >= l && s <= r) {
            dp[j] = std::max(dp[j], dp[i] + 1);
        }
        s -= a[i];
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
