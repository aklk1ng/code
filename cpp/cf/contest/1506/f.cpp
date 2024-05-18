#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    auto isLeft = [&](int R, int C) { return (R + C) % 2 == 0; };
    auto isRight = [&](int R, int C) { return (R + C) % 2 == 1; };
    auto cal = [&](int r1, int c1, int r2, int c2) {
        if (r1 - c1 == r2 - c2) {
            return isRight(r1, c1) ? 0 : r2 - r1;
        }
        r2 -= r1 - 1;
        c2 -= c1 - 1;
        if (isLeft(r1, c1)) {
            return (r2 - c2) / 2;
        } else {
            return (r2 - c2 + 1) / 2;
        }
    };
    std::vector<std::pair<int, int>> pts;
    for (int i = 0; i < n; i++) {
        pts.emplace_back(r[i], c[i]);
    }
    std::sort(pts.begin(), pts.end());
    int R = 1, C = 1, ans = 0;
    for (auto &[nr, nc] : pts) {
        ans += cal(R, C, nr, nc);
        R = nr;
        C = nc;
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
