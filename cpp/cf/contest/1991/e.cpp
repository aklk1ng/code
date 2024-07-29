#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector g(n + 1, std::vector<int>());
    std::vector<int> colors(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok = true;
    colors[1] = 1;
    auto dfs = [&](auto self, int v) -> void {
        for (auto &u : g[v]) {
            if (!colors[u]) {
                colors[u] = 3 - colors[v];
                self(self, u);
            } else if (colors[u] + colors[v] != 3) {
                ok = false;
            }
        }
    };
    dfs(dfs, 1);
    if (!ok) {
        std::cout << "Alice\n";
        for (int i = 1; i <= n; i++) {
            std::cout << "1 2" << std::endl;
            int v, c;
            std::cin >> v >> c;
        }
    } else {
        std::cout << "Bob" << std::endl;
        std::vector<int> part1, part2;
        for (int i = 1; i <= n; i++)
            if (colors[i] == 1) {
                part1.push_back(i);
            } else {
                part2.push_back(i);
            }
        for (int i = 1; i <= n; i++) {
            int color1, color2;
            std::cin >> color1 >> color2;
            if ((color1 == 1 || color2 == 1) && part1.size()) {
                std::cout << part1.back() << ' ' << 1 << std::endl;
                part1.pop_back();
            } else if ((color1 == 2 || color2 == 2) && part2.size()) {
                std::cout << part2.back() << ' ' << 2 << std::endl;
                part2.pop_back();
            } else if (!part1.size()) {
                int chosenColor = (color1 == 1 ? color2 : color1);
                std::cout << part2.back() << ' ' << chosenColor << std::endl;
                part2.pop_back();
            } else {
                int chosenColor = (color1 == 2 ? color2 : color1);
                std::cout << part1.back() << ' ' << chosenColor << std::endl;
                part1.pop_back();
            }
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
