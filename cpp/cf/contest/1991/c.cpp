#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    bool odd = false, even = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
            odd = true;
        } else {
            even = true;
        }
    }
    if (odd && even) {
        std::cout << "-1\n";
    } else {
        std::vector<int> ops;
        for (int i = 29; i >= 0; i--) {
            ops.push_back(1 << i);
        }
        if (even) {
            ops.push_back(1);
        }
        std::cout << ops.size() << '\n';
        for (auto &e : ops) {
            std::cout << e << " \n"[e == ops.back()];
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
