#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, a, b;
    std::cin >> n >> a >> b;
    if (b <= a) {
        std::cout << n * a << '\n';
    } else {
        ll k = std::min(b - a + 1, n);
        std::cout << (b - k + 1) * n + k * (k - 1) / 2 << '\n';
    }
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
