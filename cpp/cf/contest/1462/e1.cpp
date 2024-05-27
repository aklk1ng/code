#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    ll ans = 0;
    for (int i = 2; i < n; i++) {
        ans += cnt[i - 1] * cnt[i] * cnt[i + 1];
    }
    for (int i = 1; i < n; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2 * cnt[i + 1];
    }
    for (int i = 2; i <= n; i++) {
        ans += cnt[i - 1] * cnt[i] * (cnt[i] - 1) / 2;
    }
    for (int i = 2; i < n; i++) {
        ans += cnt[i - 1] * cnt[i + 1] * (cnt[i + 1] - 1) / 2;
    }
    for (int i = 2; i < n; i++) {
        ans += cnt[i + 1] * cnt[i - 1] * (cnt[i - 1] - 1) / 2;
    }
    for (int i = 1; i <= n; i++) {
        ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    }
    std::cout << ans << "\n";
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
