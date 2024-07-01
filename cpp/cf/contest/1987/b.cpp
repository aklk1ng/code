#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    ll pref = 0, s = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        pref = std::max(pref, (ll)a[i]);
        ll d = pref - a[i];
        s += d;
        mx = std::max(mx, d);
    }
    std::cout << s + mx << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
