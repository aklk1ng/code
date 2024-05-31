#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int l, r;
    std::cin >> l >> r;

    int ans = 0;
    while (l || r) {
        ans += r - l;
        l /= 10;
        r /= 10;
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
