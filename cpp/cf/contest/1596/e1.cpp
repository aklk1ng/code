#include <bits/stdc++.h>
using ll = long long;
const int INF = 1e9 + 7;

ll pow(ll a, ll b, ll mod) {
    if (b == 0) {
        return 1;
    }
    ll ans = pow(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2) {
        ans *= a;
    }
    return ans % mod;
}

void solve() {
    int k;
    std::cin >> k;
    ll n = (1LL << k) - 2;
    ll ans = pow(4, n, INF);
    ans *= 6;
    ans %= INF;
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
