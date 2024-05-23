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

    ll ans = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = x + 1; y < 3; y++) {
            std::map<std::pair<int, int>, int> cnt;
            for (int i = 0; i < n - 2; i++) {
                ans += cnt[{a[i + x], a[i + y]}]++;
            }
        }
    }
    std::map<std::tuple<int, int, int>, int> cnt;
    for (int i = 0; i < n - 2; i++) {
        ans -= 3 * cnt[{a[i], a[i + 1], a[i + 2]}]++;
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
