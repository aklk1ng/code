#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll x, y, z, k;
    std::cin >> x >> y >> z >> k;

    ll ans = 0;
    for (int a = 1; a <= x; a++) {
        for (int b = 1; b <= y; b++) {
            if (k % (a * b)) {
                continue;
            }
            ll c = k / (a * b);
            if (c > z) {
                continue;
            }
            ll ways = (ll)(x - a + 1) * (y - b + 1) * (z - c + 1);
            ans = std::max(ans, ways);
        }
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
    while (T--) {
        solve();
    }

    return 0;
}
