#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b;
    std::cin >> a >> b;

    for (int i = 0; i < 30; i++) {
        if ((a & (1 << i)) != (b & (1 << i))) {
            std::cout << (1LL << i) << '\n';
            break;
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
