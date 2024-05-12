#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<ll> g(a.begin(), a.begin() + 2);
    for (int i = 0; i < n; i++) {
        g[i % 2] = std::__gcd(g[i % 2], a[i]);
    }
    std::vector<bool> good(2, true);
    for (int i = 0; i < n; i++) {
        good[i % 2] = good[i % 2] && (a[i] % g[(i % 2) ^ 1] > 0);
    }
    ll ans = 0;
    for (int i = 0; i < 2; i++) {
        if (good[i]) {
            ans = std::max(ans, g[i ^ 1]);
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
