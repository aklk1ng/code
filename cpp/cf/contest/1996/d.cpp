#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x;
    std::cin >> n >> x;

    ll ans = 0;
    for (int a = 1; a <= std::min(n, x); a++) {
        for (int b = 1; a * b <= n && a + b <= x; b++) {
            ans += std::min((n - a * b) / (a + b), x - (a + b));
        }
    }
    std::cout << ans << '\n';
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
