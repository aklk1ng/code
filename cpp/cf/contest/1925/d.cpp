#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

ll pow(ll a, ll b, ll p) {
    if (b == 0) {
        return 1;
    }
    if (a == 0) {
        return 0;
    }
    int res = 1;
    a %= p;
    while (b > 0) {
        if (b & 1) {
            res = (1ll * res * a) % p;
        }
        b >>= 1;
        a = (1ll * a * a) % p;
    }
    return res;
}

ll fact[N], inv[N];

void init() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
    }
    for (int i = 1; i < N; i++) {
        inv[i] = pow(fact[i], mod - 2, mod);
    }
}

ll nCr(ll n, ll r, ll p) {
    if (r > n || r < 0) {
        return 0;
    }
    if (n == r) {
        return 1;
    }
    if (r == 0) {
        return 1;
    }
    return (((fact[n] * inv[r]) % p) * inv[n - r]) % p;
}

void solve() {
    ll n, m, k;
    std::cin >> n >> m >> k;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b, f;
        std::cin >> a >> b >> f;
        sum = (sum + f) % mod;
    }

    ll den = ((n * (n - 1)) / 2ll) % mod;
    ll den_inv = pow(den, mod - 2, mod);
    ll base = (((sum * k) % mod) * den_inv) % mod;
    ll avg_inc = 0;
    for (int i = 1; i <= k; i++) {
        ll sum = ((1ll * i * (i - 1)) / 2ll) % mod;
        ll prob = (nCr(k, i, mod) * pow(den_inv, i, mod)) % mod;
        ll unpicked_prob = ((den - 1) * den_inv) % mod;
        prob = (prob * pow(unpicked_prob, k - i, mod)) % mod;
        avg_inc = (avg_inc + (sum * prob) % mod) % mod;
    }
    ll ans = (base + (m * avg_inc) % mod) % mod;
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
    init();
    while (T--) {
        solve();
    }

    return 0;
}
