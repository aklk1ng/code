#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n), rg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for (int i = 0; i < n - 1; i++) {
        g[i].push_back(i + 1);
    }
    std::vector<int> d(n, -1);
    d[0] = 0;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        for (auto &i : g[f]) {
            if (d[i] == -1) {
                d[i] = d[f] + 1;
                q.push(i);
            }
        }
    }
    std::multiset<int> s;
    std::vector<std::vector<int>> tmp(n);
    std::string ans = std::string(n - 1, '0');
    for (int i = n - 1; i >= 0; i--) {
        for (auto &j : rg[i]) {
            int max_right = i - d[j];
            s.insert(max_right);
            tmp[j].push_back(max_right);
        }
        for (auto &j : tmp[i]) {
            s.erase(s.find(j));
        }
        if (i < n - 1) {
            int p = s.empty() ? -1 : *std::prev(s.end());
            if (i >= p - 1) {
                ans[i] = '1';
            }
        }
    }
    std::cout << ans << '\n';
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
