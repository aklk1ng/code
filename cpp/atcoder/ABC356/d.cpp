#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll f(ll j, ll n) {
    ll res = ((n >> (j + 1)) << j);
    if (n & (1ll << j)) {
        res += ((n & ((1ll << j) - 1)) + 1);
    }
    return res;
}

void solve() {
    ll n, m;
    std::cin >> n >> m;
    ll ans = 0;
    for (ll i = 0; i < 60; i++) {
        if (m & (1ll << i)) {
            ans += f(i, n);
            ans %= mod;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
