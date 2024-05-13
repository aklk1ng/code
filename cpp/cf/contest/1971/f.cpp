#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll r;
    std::cin >> r;
    ll h = r, ans = 0;
    for (int i = 0; i <= r; i++) {
        while (1LL * i * i + h * h >= (r + 1) * (r + 1)) {
            h--;
        }
        ll c = h;
        while (1LL * i * i + c * c >= r * r && c > 0) {
            c--;
            ans++;
        }
    }
    std::cout << ans * 4 << '\n';
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
