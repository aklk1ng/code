#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second;
    }

    std::sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second == 1) {
            int mc;
            if (i < n / 2) {
                mc = a[n / 2].first;
            } else {
                mc = a[(n - 2) / 2].first;
            }
            ans = std::max(ans, 0LL + a[i].first + k + mc);
        }
    }
    int l = 0, r = 2e9;
    while (l != r) {
        int m = (1LL + l + r) / 2;
        int z = 0;
        std::vector<int> t;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].first >= m) {
                z++;
            } else if (a[i].second == 1) {
                t.push_back(m - a[i].first);
            }
        }
        std::reverse(t.begin(), t.end());
        int kk = k;
        for (auto &e : t) {
            if (kk >= e) {
                kk -= e;
                z++;
            }
        }
        if (z >= (n + 1) / 2) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    std::cout << std::max(ans, 0LL + a[n - 1].first + l) << '\n';
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
