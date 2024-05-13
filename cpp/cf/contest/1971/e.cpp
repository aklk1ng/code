#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<ll> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        std::cin >> b[i];
    }
    while (q--) {
        ll d;
        std::cin >> d;
        int l = 0, r = k;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] > d) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (a[r] == d) {
            std::cout << b[r] << ' ';
            continue;
        }
        ll ans = b[r] + (d - a[r]) * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);
        std::cout << ans << " \n"[q == 0];
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
