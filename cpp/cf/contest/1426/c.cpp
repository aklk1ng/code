#include <bits/stdc++.h>
using ll = long long;

void solve() {
    int n;
    std::cin >> n;

    int ans = 1e9;
    for (int i = 1; i <= n / i; i++) {
        ans = std::min(ans, i - 1 + (n - 1) / i);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
