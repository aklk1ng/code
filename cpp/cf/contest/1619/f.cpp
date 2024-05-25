#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    for (int i = 0; i < k; i++) {
        int idx = 0;
        for (int j = 0; j < m; j++) {
            int sz = n / m;
            if (j < n % m) {
                sz++;
            }
            std::cout << sz;
            for (int t = 0; t < sz; t++) {
                std::cout << ' ' << p[idx++] + 1;
            }
            std::cout << '\n';
        }
        std::rotate(p.begin(), p.begin() + (n % m) * ((n + m - 1) / m),
                    p.end());
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
