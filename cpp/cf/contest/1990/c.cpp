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

    std::vector<bool> c(n + 1);
    auto cal = [&]() {
        c.assign(n + 1, false);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (c[a[i]]) {
                mx = std::max(mx, a[i]);
            }
            c[a[i]] = true;
            a[i] = mx;
        }
    };
    ll ans = std::accumulate(a.begin() + 1, a.end(), 0LL);
    cal();
    ans += std::accumulate(a.begin() + 1, a.end(), 0LL);
    cal();
    for (int i = 1; i <= n; i++) {
        ans += (n - i + 1) * 1LL * a[i];
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
