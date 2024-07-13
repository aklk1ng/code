#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;

    std::string sn = std::to_string(n);
    int len = sn.length();
    std::vector<std::pair<int, int>> ans;
    for (int a = 1; a <= 10000; a++) {
        int mi = std::max(1, len * a - 5);;
        int mx = len * a;
        for (int b = mi; b < mx; b++) {
            int x = n * a - b;
            ll y = 0;
            for (int i = 0; i < len * a - b; i++) {
                y = y * 10 + (sn[i % len] - '0');
            }
            if (x == y) {
                ans.emplace_back(a, b);
            }
        }
    }
    std::cout << ans.size() << '\n';
    for (auto &p : ans) {
        std::cout << p.first << ' ' << p.second << '\n';
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
