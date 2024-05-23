#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x, y;
    std::cin >> x >> y;

    int ans = (y + 1) / 2;
    x -= (ans * 5 * 3 - y * 2 * 2);
    x = std::max(x, 0);
    ans += (x + 5 * 3 - 1) / 15;
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
