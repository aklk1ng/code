#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, m;
    std::cin >> n >> m;

    ll ans = 0;
    ll l = std::max(0LL, n - m), r = n + m;
    for (int i = 31; ~i; i--) {
        if ((l & (1LL << i)) || (r & (1LL << i)) ||
            (l >> (i + 1)) != (r >> (i + 1))) {
            ans |= 1LL << i;
        }
    }
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
