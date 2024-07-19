#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    ll x;
    std::cin >> n >> x;
    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
    std::vector<int> dp(n + 2);
    for (int i = n - 1; i >= 0; i--) {
        int q = std::upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
        dp[i] = dp[q] + q - i - 1;
    }
    std::cout << std::accumulate(dp.begin(), dp.end(), 0LL) << '\n';
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
