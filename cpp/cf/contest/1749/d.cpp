#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int x, int y) {
    x += y;
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
    return x;
}

int sub(int x, int y) { return add(x, -y); }

int mul(int x, int y) { return (x * 1ll * y) % mod; }

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) {
            z = mul(z, x);
        }
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

bool prime(int x) {
    for (int i = 2; i * 1ll * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {

    int n;
    ll m;
    std::cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = add(ans, binpow(m % mod, i));
    }
    ll cur = 1;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (cur > m) {
            continue;
        }
        if (prime(i)) {
            cur *= i;
        }
        cnt = mul(cnt, (m / cur) % mod);
        ans = sub(ans, cnt);
    }
    std::cout << ans << '\n';
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
