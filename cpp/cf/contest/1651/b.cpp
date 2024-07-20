#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    if (pow(3, n - 1) > 1e9) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            std::cout << (ll)pow(3, (ll)i) << " \n"[i == n - 1];
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
