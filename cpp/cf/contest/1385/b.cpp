#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> vis(n), p;
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[a[i] - 1]) {
            vis[a[i] - 1] = true;
            p.push_back(a[i]);
        }
    }
    for (auto &e : p) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
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
