#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g[p - 1].push_back(i);
    }

    auto check = [&](auto self, int v, int x) -> bool {
        if (x > 1e9) {
            return false;
        }
        bool ok = true;
        if (v) {
            x += std::max(0, x - a[v]);
        }
        for (auto &u : g[v]) {
            ok = false;
            if (!self(self, u, x)) {
                return false;
            }
        }
        return !ok || x <= a[v];
    };
    int l = 1, r = 1e9;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(check, 0, m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    std::cout << a[0] + l - 1 << '\n';
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
