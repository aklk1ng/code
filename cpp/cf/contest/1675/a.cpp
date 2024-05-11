#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    int ax = std::min(a, x);
    int by = std::min(b, y);
    a -= ax;
    x -= ax;
    b -= by;
    y -= by;
    std::cout << (c >= x + y ? "YES" : "NO") << '\n';
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
