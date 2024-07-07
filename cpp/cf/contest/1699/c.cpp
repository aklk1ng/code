#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    ll ans = 1;
    int l = pos[0], r = pos[0];
    for (int i = 1; i < n; i++) {
        if (pos[i] < l) {
            l = pos[i];
        } else if (pos[i] > r) {
            r = pos[i];
        } else {
            ans = ans * (r - l + 1 - i) % mod;
        }
    }
    std::cout << ans << '\n';
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
