#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    int mx = -1;
    std::vector<int> d(2 * k);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        d[x % (2 * k)]++;
        mx = std::max(mx, x);
    }

    int cnt = 0, ans = INT_MAX;
    for (int i = 0; i <= k - 2; i++) {
        cnt += d[i];
    }
    for (int l = 0, r = k - 1; l < 2 * k; l++, r++) {
        if (r >= 2 * k) {
            r -= 2 * k;
        }
        if (cnt += d[r]; cnt == n) {
            int wait = (r - mx) % (2 * k);
            if (wait < 0) {
                wait += 2 * k;
            }
            ans = std::min(ans, mx + wait);
        }
        cnt -= d[l];
    }
    if (ans == INT_MAX) {
        ans = -1;
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
