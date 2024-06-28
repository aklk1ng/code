#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;

    int svx = 1, svy = 1;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            bool ok = true;
            for (int dx : {-2, -1, 1, 2}) {
                for (int dy : {-2, -1, 1, 2}) {
                    if (abs(dx * dy) != 2) {
                        continue;
                    }
                    if (1 <= x + dx && x + dx <= n && 1 <= y + dy &&
                        y + dy <= m) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                svx = x;
                svy = y;
            }
        }
    }
    std::cout <<  svx << ' ' << svy << '\n';
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
