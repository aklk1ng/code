#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll a, b, d, k = 0, inv, tot = 1;
    std::cin >> a >> b >> d;
    a |= b;
    if (a % d == 0) {
        std::cout << a << '\n';
        return;
    }
    while (a % 2 == 0 && d % 2 == 0) {
        a /= 2;
        d /= 2;
        k++;
    }
    inv = (d + 1) / 2;
    if (a % 2 && d % 2 == 0) {
        std::cout << "-1\n";
        return;
    }
    for (int i = 0; i < 30 - k; i++) {
        tot = tot * inv % d;
    }
    std::cout << ((tot << (30 - k)) - 1) * (1LL << k) << '\n';
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
