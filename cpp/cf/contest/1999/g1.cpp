#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int l = 2, r = 1000;
    while (l < r) {
        int m = l + (r - l) / 2;
        std::cout << "? 1 " << m << std::endl;
        int x;
        std::cin >> x;
        if (x == m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    std::cout << "! " << l << std::endl;
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
