#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, s, m;
    std::cin >> n >> s >> m;
    std::vector<std::pair<int, int>> g(n + 2);
    g[0] = {0, 0};
    g[1] = {m, m};
    for (int i = 2; i < n + 2; i++) {
        int x, y;
        std::cin >> x >> y;
        g[i] = {x, y};
    }

    std::sort(g.begin(), g.end());
    for (int i = 1; i < n + 2; i++) {
        if (g[i].first - g[i - 1].second >= s) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
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
