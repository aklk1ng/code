#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for (int s = 2; s <= 2 * n; ++s) {
        int cur = 0;
        for (int i = 1; i < (s + 1) / 2; ++i) {
            if (s - i > n) {
                continue;
            }
            cur += std::min(cnt[i], cnt[s - i]);
        }
        if (s % 2 == 0) {
            cur += cnt[s / 2] / 2;
        }
        ans = std::max(ans, cur);
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
