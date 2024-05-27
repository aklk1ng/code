#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
ll fact[N];
ll inv[N];

ll pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

void init() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = pow(fact[i], mod - 2);
    }
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> v(n);
    for (ll &e : v) {
        std::cin >> e;
    }

    std::sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = std::upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
        ans = (ans + C(r - l, m - 1)) % mod;
    }
    std::cout << ans << "\n";
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
