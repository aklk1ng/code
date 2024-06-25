#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> c(n), x(m);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> x[i];
    }

    std::vector<ll> g(m);
    for (int i = 0; i < n - 1; i++) {
        g[c[i]] |= 1LL << c[i + 1];
        g[c[i + 1]] |= 1LL << c[i];
    }
    g[c[0]] |= 1LL << c[0];
    g[c[n - 1]] |= 1LL << c[n - 1];
    int mid = m / 2;
    std::vector<int> dp(1 << mid, 1e9);
    for (int mask = 0; mask < 1 << (m - mid); mask++) {
        ll chk = 0;
        int tot = 0;
        for (int i = 0; i < m - mid; i++) {
            if ((mask >> i) & 1) {
                tot += x[i + mid];
            } else {
                chk |= g[i + mid];
            }
        }
        if (((chk >> mid) | mask) != mask) {
            continue;
        }
        chk &= (1ll << mid) - 1;
        dp[chk] = std::min(dp[chk], tot);
    }
    for (int i = 0; i < mid; i++) {
        for (int mask = 0; mask < 1 << mid; mask++) {
            if (!((mask >> i) & 1)) {
                dp[mask | (1 << i)] = std::min(dp[mask | (1 << i)], dp[mask]);
            }
        }
    }
    int ans = 1e9;
    for (int mask = 0; mask < 1 << mid; mask++) {
        ll chk = 0;
        int tot = 0;
        for (int i = 0; i < mid; i++) {
            if ((mask >> i) & 1) {
                tot += x[i];
            } else {
                chk |= g[i];
            }
        }
        chk &= (1ll << mid) - 1;
        if ((chk | mask) != mask) {
            continue;
        }
        ans = std::min(ans, dp[mask] + tot);
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
