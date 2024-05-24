#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    auto cal = [&](ll t) -> ll {
        if (t <= 0) {
            return 0;
        }
        return (t * (t - 1)) / 2LL;
    };
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        if (i != p[i] - 1) {
            s.insert(p[i] + i);
        }
    }
    if (s.empty()) {
        std::cout << cal(2 * n + 1) << '\n';
        return;
    }
    ll ans = s.size() == 1;
    int l = 0, r = 2 * n;
    for (int i = 0; i < n; i++) {
        if (i != p[i] - 1) {
            l = std::max(l, p[i] + 1);
            r = std::min(r, p[i] + n);
        }
    }
    ans += cal(2LL * n) - cal(l - 1) - cal(2LL * n - r);
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
