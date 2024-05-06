#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x, y;
    std::cin >> x >> y;

    int d = x * x + y * y;
    int r = 0;
    while (r * r < d) {
        r++;
    }
    int ans = 2;
    if (r * r == d) {
        ans = 1;
    }
    if (!x && !y) {
        ans = 0;
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
