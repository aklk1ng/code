#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, h, m;
    std::cin >> n >> h >> m;

    int time = 60 * h + m;
    int ans = 24 * 60;
    for (int i = 0; i < n; i++) {
        std::cin >> h >> m;
        int t = 60 * h + m - time;
        if (t < 0) {
            t += 24 * 60;
        }
        ans = std::min(ans, t);
    }
    std::cout << ans / 60 << ' ' << ans % 60 << '\n';
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
