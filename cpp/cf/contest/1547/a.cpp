#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::vector<int> a(2), b(2), f(2);
    std::cin >> a[0] >> a[1];
    std::cin >> b[0] >> b[1];
    std::cin >> f[0] >> f[1];

    int ans = std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
    if ((a[0] == b[0] && a[0] == f[0] && std::min(a[1], b[1]) < f[1] &&
         f[1] < std::max(a[1], b[1])) ||
        (a[1] == b[1] && a[1] == f[1] && std::min(a[0], b[0]) < f[0] &&
         f[0] < std::max(a[0], b[0]))) {
        ans += 2;
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
