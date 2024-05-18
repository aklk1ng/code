#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        v[y] |= (1 << (x - 1));
    }
    const int FULL = 3;
    v[2e9] = FULL;
    int lst = 0, color = 0;
    for (auto &[x, mask] : v) {
        if (mask != FULL && lst) {
            int cur = (x + mask) % 2;
            if (color == cur) {
                std::cout << "NO\n";
                return;
            } else {
                lst = 0;
            }
        } else if (mask == FULL && lst) {
            std::cout << "NO\n";
            return;
        } else if (mask != FULL) {
            color = (x + mask) % 2;
            lst = 1;
        }
    }
    std::cout << "YES\n";
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
