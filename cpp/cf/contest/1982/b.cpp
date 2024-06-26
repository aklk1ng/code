#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll x, y, k;
    std::cin >> x >> y >> k;

    while (k > 0 && x != 1) {
        ll ost = (x / y + 1) * y - x;
        ost = std::max(1LL, ost);
        ost = std::min(k, ost);
        x += ost;
        while (x % y == 0) {
            x /= y;
        }
        k -= ost;
    }
    std::cout << x + k % (y - 1) << '\n';
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
