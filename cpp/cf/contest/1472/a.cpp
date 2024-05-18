#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int w, h, n;
    std::cin >> w >> h >> n;

    int ans = 1;
    while (w % 2 == 0) {
        w /= 2;
        ans *= 2;
    }
    while (h % 2 == 0) {
        h /= 2;
        ans *= 2;
    }
    std::cout << (ans >= n ? "YES" : "NO") << '\n';
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
