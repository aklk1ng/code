#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    if (a < 0) {
        a += mod;
    }
    return a;
}

int mul(int a, int b) { return a * 1ll * b % mod; }

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int d, n, m;
    std::cin >> d >> n >> m;
    std::vector<int> inv(d + 1);
    for (int i = 0; i <= d; i++) {
        inv[i] = binpow(i, mod - 2);
    }
    std::vector<int> b(n), a(m);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    int fl = (1 << m) - 1;
    std::vector<int> ways(1 << m, 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int dist = std::abs(b[j] - a[i]);
            int mask;
            if (b[j] > a[i]) {
                int r = std::lower_bound(a.begin(), a.end(), b[j] + dist) -
                        a.begin();
                mask = fl ^ ((1 << r) - 1) ^ ((1 << (i + 1)) - 1);
            } else {
                int l = std::lower_bound(a.begin(), a.end(), b[j] - dist) -
                        a.begin();
                mask = fl ^ ((1 << i) - 1) ^ ((1 << l) - 1);
            }
            ways[mask] = mul(ways[mask], dist);
            mask ^= (1 << i);
            ways[mask] = mul(ways[mask], inv[dist]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int mask = fl; mask >= 0; mask--) {
            if ((mask >> i) & 1) {
                ways[mask ^ (1 << i)] = mul(ways[mask ^ (1 << i)], ways[mask]);
            }
        }
    }
    ways[0] = binpow(d + 1, n);
    for (int mask = 0; mask < (1 << m); mask++) {
        ways[mask] =
            mul(ways[mask], __builtin_popcount(mask) & 1 ? mod - 1 : 1);
    }
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (!((mask >> i) & 1)) {
                ways[mask ^ (1 << i)] = add(ways[mask ^ (1 << i)], ways[mask]);
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int x;
        std::cin >> x;
        int ans = binpow(d + 1, n + 1);
        for (int i = 0; i < m; i++) {
            int dist = std::abs(x - a[i]);
            int mask;
            if (x > a[i]) {
                int r =
                    std::lower_bound(a.begin(), a.end(), x + dist) - a.begin();
                mask = fl ^ ((1 << r) - 1) ^ ((1 << (i + 1)) - 1);
            } else {
                int l =
                    std::lower_bound(a.begin(), a.end(), x - dist) - a.begin();
                mask = fl ^ ((1 << i) - 1) ^ ((1 << l) - 1);
            }
            ans = add(ans, mul(add(ways[mask], -ways[mask ^ (1 << i)]), dist));
        }
        std::cout << ans << '\n';
    }
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
