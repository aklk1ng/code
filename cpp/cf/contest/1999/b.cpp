#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    auto f = [&](int x, int y) {
        if (x > y) {
            return 1;
        }
        if (x == y) {
            return 0;
        }
        return -1;
    };
    int ans = 0;
    if (f(a, c) + f(b, d) > 0) {
        ans++;
    }
    if (f(a, d) + f(b, c) > 0) {
        ans++;
    }
    if (f(b, c) + f(a, d) > 0) {
        ans++;
    }
    if (f(b, d) + f(a, c) > 0) {
        ans++;
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
