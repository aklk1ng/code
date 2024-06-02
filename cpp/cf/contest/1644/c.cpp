#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> mx(n + 1, INT_MIN);
    mx[0] = 0;
    for (int l = 0; l < n; l++) {
        int s = 0;
        for (int r = l; r < n; r++) {
            s += a[r];
            mx[r - l + 1] = std::max(mx[r - l + 1], s);
        }
    }
    std::vector<int> ans(n + 1);
    for (int k = 0; k <= n; k++) {
        int bst = 0;
        for (int i = 0; i <= n; i++) {
            bst = std::max(bst, mx[i] + std::min(k, i) * x);
        }
        ans[k] = bst;
    }
    for (int i = 0; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
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
