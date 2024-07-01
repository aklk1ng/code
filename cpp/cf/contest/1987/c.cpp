#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    int ans = h.back();
    for (int i = n - 2; i >= 0; i--) {
        ans = std::max(ans + 1, h[i]);
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
