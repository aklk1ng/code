#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    if (n < 6) {
        if (n == 1) {
            std::cout << "1\n" << "1\n";
        } else if (n == 2) {
            std::cout << "2\n" << "1 2\n";
        } else if (n == 3) {
            std::cout << "2\n" << "1 2 2\n";
        } else if (n == 4) {
            std::cout << "3\n" << "1 2 2 3\n";
        } else if (n == 5) {
            std::cout << "3\n" << "1 2 2 3 3\n";
        }
    } else {
        std::cout << "4\n";
        for (int i = 1; i <= n; i++) {
            std::cout << i % 4 + 1 << " \n"[i == n];
        }
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
