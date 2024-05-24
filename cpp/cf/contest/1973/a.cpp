#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::vector<int> p(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> p[i];
    }

    int ans = -1;
    for (int i = 0; i <= std::min(p[0], p[1]); i++) {
        for (int j = 0; j <= std::min(p[0], p[2]); j++) {
            for (int k = 0; k <= std::min(p[1], p[2]); k++) {
                if ((p[0] - i - j) % 2 || p[0] < i + j) {
                    continue;
                }
                if ((p[1] - i - k) % 2 || p[1] < i + k) {
                    continue;
                }
                if ((p[2] - j - k) % 2 || p[2] < j + k) {
                    continue;
                }
                ans = std::max(ans, i + j + k);
            }
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
