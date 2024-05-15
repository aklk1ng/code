#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int k;
    std::cin >> k;

    for (int i = 1;; i++) {
        if (i % 3 == 0 || i % 10 == 3) {
            continue;
        }
        if (--k == 0) {
            std::cout << i << '\n';
            return;
        }
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
