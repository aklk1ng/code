#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll x, y, a, b;
    std::cin >> x >> y >> a >> b;

    ll l = 0, r = 1e9 + 100;
    if (a == b) {
        std::cout << std::min(x, y) / a << '\n';
        return;
    }
    if (a < b) {
        std::swap(a, b);
    }
    while (l + 1 != r) {
        ll m = (l + r) / 2;
        ll right = floorl((x - m * b) * 1.0L / (a - b));
        ll left = ceill((y - m * a) * 1.0L / (b - a));
        if (std::max(left, 0LL) <= std::min(right, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << l << '\n';
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
