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

    std::set<ll> d;
    d.insert(0);
    ll cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        if (d.count(cur)) {
            ans++;
            d.clear();
            d.insert(0);
            cur = a[i];
        }
        d.insert(cur);
    }
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
