#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string t;
    std::cin >> t;

    std::vector<int> edge(26, -1), redge(26, -1);
    auto get = [&](int c) {
        int len = 0;
        int cur = c;
        while (edge[cur] != -1) {
            len++;
            cur = edge[cur];
        }
        return std::make_pair(cur, len);
    };
    std::vector<int> v;
    for (auto &c : t) {
        v.push_back(c - 'a');
    }
    for (int i = 0; i < n; i++) {
        if (edge[v[i]] == -1) {
            for (int c = 0; c < 26; c++) {
                if (redge[c] == -1) {
                    auto [lst, len] = get(c);
                    if (lst != v[i] || len == 25) {
                        edge[v[i]] = c;
                        redge[c] = v[i];
                        break;
                    }
                }
            }
        }
        v[i] = edge[v[i]];
    }
    for (int i = 0; i < n; i++) {
        t[i] = v[i] + 'a';
    }
    std::cout << t << '\n';
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
