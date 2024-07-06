#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    int mix = 0, miy = 0, mxx = 0, mxy = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        mix = std::min(mix, x);
        miy = std::min(miy, y);
        mxx = std::max(mxx, x);
        mxy = std::max(mxy, y);
    }


    std::cout << 2 * (mxx + mxy - mix - miy) << '\n';
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
