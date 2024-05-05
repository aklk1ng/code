#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto cal = [&](auto self, int i, int sum) {
        if (i == n) {
            return 0;
        }
        for (int j = i + 1, cur = 0; j <= n; j++) {
            cur += a[j - 1];
            if (cur > sum) {
                return n;
            }
            if (cur == sum) {
                return std::max(j - i, self(self, j, sum));
            }
        }
        return n;
    };
    int ans = n;
    for (int i = 1, sum = 0; i < n; i++) {
        sum += a[i - 1];
        ans = std::min(ans, cal(cal, 0, sum));
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
