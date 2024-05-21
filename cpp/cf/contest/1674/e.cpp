#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        int cur = 0;
        int x = a[i], y = a[i + 1];
        if (x < y) {
            std::swap(x, y);
        }
        int cnt = std::min(x - y, (x + 1) / 2);
        cur += cnt;
        x -= 2 * cnt;
        y -= cnt;
        if (x > 0 && y > 0) {
            cur += (x + y + 2) / 3;
        }
        ans = std::min(ans, cur);
    }
    for (int i = 0; i < n - 2; i++) {
        int cur = 0;
        int x = a[i], y = a[i + 2];
        if (x < y) {
            std::swap(x, y);
        }
        int cnt = (x - y + 1) / 2;
        cur += cnt;
        cur += y;
        ans = std::min(ans, cur);
    }
    std::sort(a.begin(), a.end());
    std::cout << std::min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
