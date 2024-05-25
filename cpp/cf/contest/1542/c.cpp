#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
    ll n;
    std::cin >> n;

    ll g = 1, ans = 0;
    for (ll i = 1; g <= n; i++) {
        g = g / std::__gcd(g, i) * i;
        if (g > n) {
            break;
        }
        ans += n / g;
    }
    std::cout << (ans + n) % mod << '\n';
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
