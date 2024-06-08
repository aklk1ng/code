#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    std::vector<ll> f(21);
    f[0] = 1;
    for (int i = 1; i < 21; i++) {
        f[i] = f[i - 1] * i;
    }
    ll ans = f[n] / f[n / 2] / f[n / 2];
    ans *= f[n / 2 - 1];
    ans *= f[n / 2 - 1];
    ans /= 2;
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
