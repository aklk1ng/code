#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::vector<int> ps(2);
    std::vector<ll> ts(2);
    int h, s;
    for (int i = 0; i < 2; i++) {
        std::cin >> ps[i] >> ts[i];
    }
    std::cin >> h >> s;
    ll ans = 1e18;
    std::vector<ll> dp(h + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 1; j <= h - i; j++) {
            for (int k = 0; k < 2; k++) {
                int ni = std::min((ll)h,
                                  i + j * (ps[k] - s) +
                                      j * ts[k] / ts[k ^ 1] * (ps[k ^ 1] - s));
                if (ni == h) {
                    ans = std::min(ans, dp[i] + j * ts[k]);
                }
                if (j * ts[k] >= ts[k ^ 1]) {
                    ni = std::min((ll)h, i + (j - 1) * (ps[k] - s) +
                                             (j * ts[k] / ts[k ^ 1] - 1) *
                                                 (ps[k ^ 1] - s) +
                                             (ps[0] + ps[1] - s));
                    dp[ni] = std::min(dp[ni], dp[i] + j * ts[k]);
                }
            }
        }
    }
    ans = std::min(ans, dp[h]);
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
