#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    ll x;
    std::cin >> x;

    std::vector<int> ans(31);
    for (int i = 0; i < 30; i++) {
        if (1LL & (x >> i)) {
            if (ans[i]) {
                ans[i + 1] = 1;
                ans[i] = 0;
            } else if (i > 0) {
                if (ans[i - 1] == 1) {
                    ans[i + 1] = 1;
                    ans[i - 1] = -1;
                } else {
                    ans[i] = 1;
                }
            } else if (i == 0) {
                ans[i] = 1;
            }
        }
    }
    std::cout << "31\n";
    for (int i = 0; i <= 30; i++) {
        std::cout << ans[i] << " \n"[i == 30];
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
