#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    std::vector<int> sum(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }

    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += sum[i];
    }
    if (tot % n) {
        std::cout << "-1\n";
        return;
    }
    tot /= n;
    std::vector<std::tuple<int, int, int>> ans;
    std::vector<int> g, l;
    g.reserve(n), l.reserve(n);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (sum[i] > tot && a[i][j]) {
                g.push_back(i);
            }
            if (sum[i] < tot && !a[i][j]) {
                l.push_back(i);
            }
        }
        for (int i = 0; i < std::min(l.size(), g.size()); i++) {
            sum[l[i]]++, sum[g[i]]--;
            ans.emplace_back(l[i], g[i], j);
        }
        l.clear(), g.clear();
    }
    std::cout << ans.size() << '\n';
    for (auto &[i, j, k] : ans) {
        std::cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
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
