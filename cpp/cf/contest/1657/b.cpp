#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, B, x, y;
    std::cin >> n >> B >> x >> y;

    ll cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cur += (cur + x <= B ? x : -y);
        ans += cur;
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
