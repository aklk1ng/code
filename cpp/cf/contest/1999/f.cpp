#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

std::vector<ll> fact(N);

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i ]= (fact[i - 1] * i) % mod;
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        ones += a[i];
    }

    auto pw = [&](ll a, ll b) {
        int64_t r = 1;
        while (b > 0) {
            if (b & 1)
                r = (r * a) % mod;
            b /= 2;
            a = (a * a) % mod;
        }
        return r;
    };
    auto cal = [&](ll x, ll y) -> ll {
        if (x < y) {
            return 0;
        }
        return (fact[x] * pw((fact[x - y] * fact[y]) % mod, mod - 2)) % mod;
    };
    ll ans = 0;
    for (int i = k / 2 + 1; i <= std::min(ones, k); i++) {
        ans += cal(ones, i) * cal(n - ones, k - i) % mod;
        ans %= mod;
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
    init();
    while (_--) {
        solve();
    }

    return 0;
}
