#include <bits/stdc++.h>
using ll = long long;
const int md = 999999893;

ll modex(ll a, ll b, ll m) {
    a = a % m;
    if (b == 0) {
        return 1;
    }
    ll tmp = modex(a, b / 2, m);
    tmp = (tmp * tmp) % m;
    if (b % 2) {
        tmp = (tmp * a) % m;
    }
    return tmp;
}

ll mod(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    ll c = std::__gcd(a, b);
    a = a / c;
    b = b / c;
    c = modex(b, m - 2, m);
    return (a * c) % m;
}

void solve() {
    ll n;
    std::cin >> n;

    ll b = modex(2, n / 2, md) - 1;
    ll a;
    if (n % 2) {
        a = modex(2, n / 2 + 1, md) - 1;
    } else {
        a = modex(2, n / 2, md) - 1;
    }
    ll tmp = (a + 1) * (a + 1);
    tmp %= md;
    tmp -= 2 * b * b;
    tmp %= md;
    ll ans = mod(2 * b, tmp, md);
    ans += md;
    ans %= md;
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
    while (T--) {
        solve();
    }

    return 0;
}
