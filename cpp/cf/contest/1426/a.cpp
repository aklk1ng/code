#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x;
    std::cin >> n >> x;

    if (n <= 2) {
        std::cout << "1\n";
    } else {
        std::cout << (n - 3) / x + 2 << '\n';
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
