#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll get(int x) { return x * 1ll * (x + 1) / 2; }

void solve() {
    int k;
    ll x;
    std::cin >> k >> x;

    ll l = 1, r = 2 * k - 1;
    ll res = 2 * k - 1;
    bool over = false;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (mid >= k) {
            over = (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
        } else {
            over = (get(mid) >= x);
        }
        if (over) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << res << '\n';
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
