#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    ll m;
    std::cin >> n >> m;
    std::map<int, int> f;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        f[a]++;
    }

    ll ans = 0;
    for (auto [x, y] : f) {
        ans = std::max(ans, 1LL * x * std::min<ll>(y, m / x));
        if (f.contains(x + 1)) {
            int z = f[x + 1];
            for (int i = 1; i <= y && 1LL * i * x <= m; i++) {
                ans = std::max(
                    ans, 1LL * i * x +
                             1LL * (x + 1) *
                                 std::min<ll>(z, (m - 1LL * i * x) / (x + 1)));
            }
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
