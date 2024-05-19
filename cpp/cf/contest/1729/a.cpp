#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int d1 = a - 1;
    int d2 = std::abs(b - c) + c - 1;
    int ans = 0;
    if (d1 <= d2) {
        ans++;
    }
    if (d1 >= d2) {
        ans += 2;
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
