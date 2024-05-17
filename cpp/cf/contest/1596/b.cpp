#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;

    ll p = 1, ans = 0;
    for (int i = 0; i < 31; i++) {
        if (k & (1 << i)) {
            ans = (ans + p) % mod;
        }
        p *= n;
        p %= mod;
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
