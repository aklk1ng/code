#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    if (n == 3) {
        std::cout << "-1\n";
    } else {
        for (int i = 3; i <= n; i++) {
            std::cout << i << ' ';
        }
        std::cout << 2 << ' ' << 1 << '\n';
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
