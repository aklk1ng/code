#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int x, y;
    std::cin >> x >> y;

    std::cout << std::min(x, y) << ' ' << std::max(x, y) << '\n';
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
