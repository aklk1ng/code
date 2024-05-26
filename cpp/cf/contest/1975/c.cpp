#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    if (n == 2) {
        std::cout << std::min(a[1], a[2]) << "\n";
    } else {
        int ans = std::min(a[1], a[2]);
        for (int i = 1; i <= n - 2; i++) {
            std::vector<int> t;
            for (int k = 0; k <= 2; k++) {
                t.push_back(a[i + k]);
            }
            std::sort(t.begin(), t.end());
            ans = std::max(ans, t[1]);
        }
        std::cout << ans << "\n";
    }
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
