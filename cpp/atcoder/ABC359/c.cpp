#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    if ((sx + sy) % 2) {
        sx--;
    }
    if ((tx + ty) % 2) {
        tx--;
    }
    ll dx = std::abs(sx - tx);
    ll dy = std::abs(sy - ty);
    std::cout << (dy + std::max(dx, dy)) / 2 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
