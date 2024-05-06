#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, C;
    std::cin >> n >> C;
    std::vector<ll> bst(C + 1);
    for (int i = 0; i < n; i++) {
        int c, d, h;
        std::cin >> c >> d >> h;
        bst[c] = std::max(bst[c], 1LL * d * h);
    }
    for (int c = 1; c <= C; c++) {
        for (int x = c; x <= C; x += c) {
            bst[x] = std::max(bst[x], bst[c] * (x / c));
        }
    }
    for (int i = 0; i < C; i++) {
        bst[i + 1] = std::max(bst[i + 1], bst[i]);
    }
    int m;
    std::cin >> m;
    for (int j = 0; j < m; j++) {
        int D;
        ll H;
        std::cin >> D >> H;
        int mi = std::upper_bound(bst.begin(), bst.end(), D * H) - bst.begin();
        if (mi > C) {
            mi = -1;
        }
        std::cout << mi << " \n"[j == m - 1];
    }
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
