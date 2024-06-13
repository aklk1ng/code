#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; i++) {
        std::cin >> g[i];
    }

    std::pair<int, int> top = {INT_MAX, INT_MAX}, bot = {INT_MIN, INT_MIN};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                top = std::min(top, {i, j});
                bot = std::max(bot, {i, j});
            }
        }
    }
    std::cout << (top.first + bot.first) / 2 + 1 << ' ' << top.second + 1
              << '\n';
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
