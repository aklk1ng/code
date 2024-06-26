#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    std::vector<int> ans(2);
    std::vector<std::pair<int, int>> p[2];
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        p[0].emplace_back(x, y);
        p[1].emplace_back(y, x);
    }
    std::sort(p[0].begin(), p[0].end());
    std::sort(p[1].begin(), p[1].end());

    int l[2]{}, r[2]{a, b};
    int lo[2]{}, hi[2]{n, n};
    for (int t = 0; t < m; t++) {
        char op;
        int k;
        std::cin >> op >> k;

        int d;
        if (op == 'L') {
            d = 1;
            l[d] += k;
        } else if (op == 'R') {
            d = 1;
            r[d] -= k;
        } else if (op == 'U') {
            d = 0;
            l[d] += k;
        } else {
            d = 0;
            r[d] -= k;
        }

        while (lo[d] < hi[d] && p[d][lo[d]].first < l[d]) {
            int y = p[d][lo[d]].second;
            if (l[!d] <= y && y < r[!d]) {
                ans[t % 2]++;
            }
            lo[d]++;
        }
        while (lo[d] < hi[d] && p[d][hi[d] - 1].first >= r[d]) {
            int y = p[d][hi[d] - 1].second;
            if (l[!d] <= y && y < r[!d]) {
                ans[t % 2]++;
            }
            hi[d]--;
        }
    }
    std::cout << ans[0] << ' ' << ans[1] << '\n';
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
