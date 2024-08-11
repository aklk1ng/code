#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x, y, k;
    std::cin >> x >> y >> k;

    for (int i = 0; i < k - k % 2; i++) {
        std::cout << x - (i & 1 ? 1 : -1) * (i / 2 + 1) << ' ' << y << '\n';
    }
    if (k & 1) {
        std::cout << x << ' ' << y << '\n';
    }
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
