#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x, n;
    std::cin >> x >> n;

    int ans = 1;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (n <= x / i) {
                ans = std::max(ans, i);
            }
            if (n <= i) {
                ans = std::max(ans, x / i);
            }
        }
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
