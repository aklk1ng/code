#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> f(n);
    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
        for (int j = 0; j < n; j++) {
            if (f[i][j] == '*') {
                p.push_back({i, j});
            }
        }
    }
    p.push_back(p[0]);
    p.push_back(p[1]);
    if (p[0].first == p[1].first) {
        p[2].first = (p[2].first + 1) % n;
        p[3].first = (p[3].first + 1) % n;
    } else if (p[0].second == p[1].second) {
        p[2].second = (p[2].second + 1) % n;
        p[3].second = (p[3].second + 1) % n;
    } else {
        std::swap(p[2].first, p[3].first);
    }

    f[p[2].first][p[2].second] = '*';
    f[p[3].first][p[3].second] = '*';
    for (int i = 0; i < n; i++) {
        std::cout << f[i] << '\n';
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
