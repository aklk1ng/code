#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    std::vector<int> b(n - 1);
    for (int &e : a) {
        std::cin >> e;
    }
    for (int &e : b) {
        std::cin >> e;
    }

    b.push_back(0);
    ll ans = 1e18;
    ll cur = 0;
    ll bal = 0;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, cur + std::max(0ll, c - bal + a[i] - 1) / a[i]);
        ll newDays = std::max(0ll, b[i] - bal + a[i] - 1) / a[i];
        cur += newDays + 1;
        bal += a[i] * newDays - b[i];
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
