#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::string a, b;
    std::cin >> a >> b;

    int n = a.size(), m = b.size();
    int ans = n + m;
    for (int i = 0; i < m; i++) {
        int j = i;
        for (auto &c : a) {
            if (j < m && c == b[j]) {
                j++;
            }
        }
        ans = std::min(ans, n + m - (j - i));
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
