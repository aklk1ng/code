#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> c[i];
    }

    int mx = *std::max_element(a.begin(), a.end()) + 1;
    std::vector<int> best(mx, std::numeric_limits<int>::max()), cal(mx);
    for (int i = 0; i < n; i++) {
        best[a[i]] = std::min(best[a[i]], a[i] - b[i]);
    }
    for (int i = 1; i < mx; i++) {
        best[i] = std::min(best[i], best[i - 1]);
    }
    for (int i = 1; i < mx; i++) {
        if (i >= best[i]) {
            cal[i] = 2 + cal[i - best[i]];
        }
    }
    ll ans = 0;
    for (auto &v : c) {
        int cur = v;
        if (cur >= mx) {
            int k = (cur - mx + 1 + best[mx - 1]) / best[mx - 1];
            ans += 2LL * k;
            cur -= k * best[mx - 1];
        }
        ans += cal[cur];
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
