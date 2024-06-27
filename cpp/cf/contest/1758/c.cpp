#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x;
    std::cin >> n >> x;
    if (n % x) {
        std::cout << "-1\n";
        return;
    }
    std::vector<int> ans(n + 1);
    std::iota(ans.begin(), ans.end(), 0);
    ans[n] = 1;
    ans[1] = x;
    while (x < n) {
        for (int i = x * 2; i <= n; i += x) {
            if (n % i == 0) {
                ans[x] = i;
                x = i;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
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
