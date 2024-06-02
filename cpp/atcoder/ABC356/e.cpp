#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(N);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i <= N - 5; i++) {
        cnt[i + 1] += cnt[i];
    }

    ll ans = 0;
    for (int c = 1; c <= N - 7; c++) {
        int d = cnt[c] - cnt[c - 1];
        for (int k = 1; k * c <= N - 7; k++) {
            ans += 1LL * k *
                   (cnt[std::min(N - 6, (k + 1) * c - 1)] - cnt[k * c - 1]) * d;
        }
        ans -= 1LL * d * (d + 1) / 2;
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
