#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int l, r, x;
    std::cin >> l >> r >> x;

    int ans = r / x + r % x;
    int m = r / x * x - 1;
    if (m >= l) {
        ans = std::max(ans, m / x + m % x);
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
