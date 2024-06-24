#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> v;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        int cnt = 1;
        while (!std::empty(v) && v.back().first <= h) {
            const auto [H, C] = v.back();
            ans -= static_cast<ll>(H) * C;
            cnt += C;
            v.pop_back();
        }
        ans += static_cast<ll>(h) * cnt;
        v.emplace_back(h, cnt);
        std::cout << ans << " \n"[i == n - 1];
    }
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
