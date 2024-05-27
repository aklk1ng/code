#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x, y, n;
    std::cin >> x >> y >> n;

    if (n - n % x + y <= n) {
        std::cout << n - n % x + y << '\n';
    } else {
        std::cout << n - n % x - (x - y) << '\n';
    }
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
