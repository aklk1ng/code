#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int x = 0, y = 0, neg = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            x += a[i];
        } else if (a[i] < b[i]) {
            y += b[i];
        } else {
            neg += a[i] < 0;
            pos += a[i] > 0;
        }
    }
    int ans = INT_MIN;
    for (int i = -neg; i <= pos; i++) {
        ans = std::max(ans, std::min(x + i, y + (pos - neg - i)));
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
