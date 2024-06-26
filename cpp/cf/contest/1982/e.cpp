#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
std::map<std::pair<ll, int>, std::tuple<int, ll, ll>> mem;

std::tuple<int, ll, ll> calc(ll n, int k) {
    if (k < 0) {
        return std::tuple{0, 0ll, 0ll};
    }
    if (n == 1) {
        return std::tuple{1, 1ll, 1ll};
    }
    int bit = 63 - __builtin_clzll(n);
    ll mid = (1ll << bit);
    if (mid == n) {
        mid >>= 1;
        if (mem.count({n, k})) {
            return mem[{n, k}];
        }
    }
    auto [f1, s1, e1] = calc(mid, k);
    auto [f2, s2, e2] = calc(n - mid, k - 1);

    int sub1 = (e1 % mod) * ((e1 + 1) % mod) % mod * 500000004 % mod;
    f1 = (f1 * 1ll - sub1 + mod) % mod;
    int sub2 = (s2 % mod) * ((s2 + 1) % mod) % mod * 500000004 % mod;
    f2 = (f2 * 1ll - sub2 + mod) % mod;

    ll p = (e1 + s2) % mod;
    int f_cur =
        (f1 * 1ll + f2 + (p * 1ll * ((p + 1) % mod) % mod * 500000004 % mod)) %
        mod;
    ll s_cur = s1;
    ll e_cur = e2;
    if (s1 == e1 && s1 != 0) {
        s_cur = (s1 + s2);
    }
    if (s2 == e2 && s2 != 0) {
        e_cur = (e1 + e2);
    }
    if ((mid << 1) == n) {
        mem[{n, k}] = std::tuple{f_cur, s_cur, e_cur};
    }
    return std::tuple{f_cur, s_cur, e_cur};
};

void solve() {
    ll n;
    int k;
    std::cin >> n >> k;
    std::cout << std::get<0>(calc(n, k)) << '\n';
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
