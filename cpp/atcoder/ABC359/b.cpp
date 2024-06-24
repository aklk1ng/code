#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n * 2);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < 2 * n - 2; i++) {
        if (a[i] == a[i + 2]) {
            ans++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
