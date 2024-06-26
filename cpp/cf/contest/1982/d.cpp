#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::vector pref(n + 1, std::vector<ll>(m + 1, 0));
    ll diff = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                cur++;
                diff += a[i][j];
            } else {
                diff -= a[i][j];
            }
            pref[i + 1][j + 1] = pref[i][j + 1] + cur;
        }
    }

    if (diff == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    int g = 0;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            int f = pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] +
                    pref[i][j];
            f = abs(k * k - 2 * f);
            g = std::__gcd(g, f);
        }
    }

    if (g == 0 || diff % g != 0) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
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
