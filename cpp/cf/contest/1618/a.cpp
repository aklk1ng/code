#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::vector<int> b(7);
    for (int i = 0; i < 7; i++) {
        std::cin >> b[i];
    }

    std::cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[0] - b[1] << '\n';
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
