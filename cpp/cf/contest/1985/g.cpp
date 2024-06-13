#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

ll mod_pow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll l, r, k;
    std::cin >> l >> r >> k;

    ll base = 9 / k + 1;
    ll pow_r = mod_pow(base, r);
    ll pow_l = mod_pow(base, l);

    ll ans = (pow_r - pow_l + mod) % mod;
    std::cout << ans << '\n';
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
