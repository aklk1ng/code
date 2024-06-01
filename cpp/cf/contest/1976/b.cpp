#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n + 1; i++) {
        std::cin >> b[i];
    }

    ll sum = 0, mx = LONG_MAX;
    for (int i = 0; i < n; i++) {
        sum += std::abs(a[i] - b[i]);
        mx = std::min(mx, std::abs(a[i] - b[n]));
        mx = std::min(mx, std::abs(b[i] - b[n]));
        if (std::min(a[i], b[i]) <= b[n] && b[n] <= std::max(a[i], b[i])) {
            mx = 0;
        }
    }
    std::cout << sum + mx + 1 << '\n';
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
