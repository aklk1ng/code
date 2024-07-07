#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), fre(n + 1);
    std::vector<ll> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        if (i && !dp[i]) {
            continue;
        }
        int frmx = 0;
        std::fill(fre.begin() + 1, fre.end(), 0);
        for (int j = i + 1; j <= n; j++) {
            if ((j - i) % 2 && frmx <= (j - i) / 2 && (!i || a[i] == a[j])) {
                dp[j] = std::max(dp[j], dp[i] + 1);
            }
            frmx = std::max(frmx, ++fre[a[j]]);
        }
    }

    int frmx = 0;
    ll ans = 0;
    std::fill(fre.begin() + 1, fre.end(), 0);
    for (int i = n; i >= 0; i--) {
        if ((n - i) % 2 == 0 && frmx <= (n - i) / 2) {
            ans = std::max(ans, dp[i]);
        }
        frmx = std::max(frmx, ++fre[a[i]]);
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
