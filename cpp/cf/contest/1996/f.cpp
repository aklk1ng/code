#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= m) {
                sum += (a[i] - m) / b[i] + 1;
            }
        }

        if (sum >= k) {
            l = m;
        } else {
            r = m;
        }
    }

    ll ans = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= l) {
            int m = (a[i] - l) / b[i] + 1;
            ans += 1LL * m * a[i] - 1LL * m * (m - 1) / 2 * b[i];
            s += m;
        }
    }
    ans -= 1LL * l * (s - k);
    std::cout << ans << "\n";
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
