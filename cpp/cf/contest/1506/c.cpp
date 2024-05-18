#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string a, b;
    std::cin >> a >> b;

    int n = a.size(), m = b.size();
    int ans = 0;
    for (int len = 1; len <= std::min(n, m); len++) {
        for (int i = 0; i + len <= n; i++) {
            for (int j = 0; j + len <= m; j++) {
                if (a.substr(i, len) == b.substr(j, len)) {
                    ans = std::max(ans, len);
                }
            }
        }
    }
    std::cout << n + m - 2 * ans << '\n';
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
