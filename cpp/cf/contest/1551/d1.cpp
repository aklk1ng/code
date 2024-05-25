#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int t = n * m / 2 - k;
    if (n & 1) {
        k -= m / 2;
        if (k < 0) {
            std::cout << "NO\n";
            return;
        }
    } else if (m & 1) {
        t -= n / 2;
        if (t < 0) {
            std::cout << "NO\n";
            return;
        }
    }
    if ((k & 1) || (t & 1)) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
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
