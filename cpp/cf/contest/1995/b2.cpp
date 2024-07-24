#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    ll m;
    std::cin >> n >> m;
    std::map<int, int> f;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        f[a[i]] = c;
    }

    ll ans = 0;
    for (auto [x, y] : f) {
        ans = std::max(ans, 1LL * x * std::min<ll>(y, m / x));
        if (f.contains(x + 1)) {
            int z = f[x + 1];
            ll c;
            if (1LL * x * y >= m) {
                c = m / x;
            } else {
                c = y + std::min<ll>(z, (m - 1LL * x * y) / (x + 1));
            }
            ans = std::max(ans, std::min(m, c * x + std::min<ll>(c, z)));
        }
    }
    std::cout << ans << '\n';
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
