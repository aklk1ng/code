#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll t, x, y;
    std::cin >> t >> x >> y;

    if (t < x + y) {
        std::cout << "No\n";
        return;
    }
    std::vector<ll> a(300), b(300);
    a[0] = t - x - y;
    b[0] = a[0] + 1;
    for (int i = 0; i < x + y; i++) {
        for (int j = i; j >= 0; j--) {
            a[j + 1] += a[j] / 2;
            a[j] -= a[j] / 2;
            b[j + 1] += b[j] / 2;
            b[j] -= b[j] / 2;
        }
    }
    ll px = -1, py = -1;
    for (int i = 0; i < 240; i++) {
        if (a[i] != b[i]) {
            px = i;
            py = x + y - i;
            break;
        }
    }
    if (x == px && y == py) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
    }
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
