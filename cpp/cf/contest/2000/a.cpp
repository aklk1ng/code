#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a;
    std::cin >> a;

    if ((a >= 102 && a <= 109) || (1010 <= a && a <= 1099)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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
