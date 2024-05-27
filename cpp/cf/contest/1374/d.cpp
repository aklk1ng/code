#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<int, int> cnt;
    int mx = 0;
    for (auto &e : a) {
        if (e % k == 0) {
            continue;
        }
        cnt[k - e % k]++;
        mx = std::max(mx, cnt[k - e % k]);
    }
    ll ans = 0;
    for (auto &[key, val] : cnt) {
        if (val == mx) {
            ans = k * 1LL * (val - 1) + key + 1;
        }
    }
    std::cout << ans << '\n';
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
