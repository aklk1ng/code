#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int k;
    std::cin >> k;
    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
        for (int j = 0; j < a[i] - 1; j++) {
            int _;
            std::cin >> _;
        }
    }

    std::sort(a.begin(), a.end(), std::greater<>());
    int ans = 0;
    for (auto &x : a) {
        for (int h = 23; h >= 0; h--) {
            int ca = ans >> h & 1, cx = x >> h & 1;
            if (!cx) {
                continue;
            }
            if (!ca) {
                ans |= 1 << h;
            } else {
                ans |= (1 << h) - 1;
                break;
            }
        }
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
