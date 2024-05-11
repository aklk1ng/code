#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1);
    std::vector<bool> leaf(n + 1, true);
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
        leaf[b[i]] = false;
    }

    if (n == 1) {
        std::cout << "1\n1\n1\n\n";
        return;
    }
    std::vector paths(n + 1, std::vector<int>());
    std::vector<bool> used(n + 1);
    int color = 0;
    for (int i = 1; i <= n; i++) {
        if (!leaf[i]) {
            continue;
        }
        used[i] = true;
        paths[color].emplace_back(i);
        int v = i;
        while (b[v] != v && !used[b[v]]) {
            v = b[v];
            used[v] = true;
            paths[color].emplace_back(v);
        }
        color++;
    }
    std::cout << color << '\n';
    for (auto &e : paths) {
        if (e.empty()) {
            continue;
        }
        std::cout << e.size() << '\n';
        std::reverse(e.begin(), e.end());
        for (auto &v : e) {
            std::cout << v << " \n"[v == e.back()];
        }
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
