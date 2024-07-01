#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> d(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        p--;
        g[p].push_back(i);
        d[i] = d[p] + 1;
    }

    std::vector<ll> b(n);
    for (int v = 0; v < n; v++) {
        if (g[v].empty()) {
            b[v] = LONG_MAX;
        } else {
            b[v] -= a[v];
            for (auto &u : g[v]) {
                b[v] += a[u];
            }
        }
    }
    ll ans = 0;
    for (int v = n - 1; v >= 0; v--) {
        std::queue<int> q;
        q.push(v);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto &u : g[i]) {
                ll delta = std::min(-b[v], b[u]);
                if (delta > 0) {
                    b[v] += delta;
                    b[u] -= delta;
                    ans += delta * (d[u] - d[v]);
                }
                q.push(u);
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
