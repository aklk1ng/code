#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int l = 1, r = 999;
    while (r - l > 2) {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        std::cout << "? " << a << ' ' << b << std::endl;
        int x;
        std::cin >> x;
        if (x == (a + 1) * (b + 1)) {
            r = a;
        } else if (x == a * b) {
            l = b;
        } else {
            l = a;
            r = b;
        }
    }
    if (r - l == 2) {
        std::cout << "? 1 " << l + 1 << std::endl;
        int x;
        std::cin >> x;
        if (x == l + 1) {
            l++;
        } else {
            r = l + 1;
        }
    }
    std::cout << "! " << r << std::endl;
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
