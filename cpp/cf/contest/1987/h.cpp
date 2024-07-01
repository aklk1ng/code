#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int ans_x = 0, ans_y = 0, cnt_q = 0;

int query(int x, int y) {
    cnt_q++;

    int res = 0;
    std::cout << "? " << y << ' ' << x << '\n';
    std::cout.flush();

    std::cin >> res;

    if (res < 0) {
        exit(0);
    }

    if (res == 0) {
        ans_x = x;
        ans_y = y;
    }

    return res;
}

void f(int lx, int rx, int ly, int ry) {
    int n = rx - lx + 1;

    if (n <= 25) {
        for (int x = lx; x <= rx; x++) {
            int lb = ly, ub = ry;

            while (lb <= ub) {
                int res = query(x, lb);

                int low_y = ((res - 1) + 1) / 2, high_y = res;

                int new_lb = lb + std::max(1, low_y),
                    new_ub = std::min(ub, lb + high_y);
                lb = new_lb;
                ub = new_ub;
            }
        }

        return;
    }

    int a = 3 * (n + 3) / 16;
    int y = std::min(ry, ly + 1);

    int x1 = lx + a - 1;
    x1 = std::max(x1, lx);
    x1 = std::min(x1, rx);

    int x2 = (lx + rx) / 2;
    x2 = std::max(x2, x1 + 1);
    x2 = std::min(x2, rx);

    int x3 = rx - a + 1;
    x3 = std::max(x3, x2 + 1);
    x3 = std::min(x3, rx);

    int m = std::min(3, ry - ly + 1);
    std::vector good(n, std::vector<bool>(m, true));

    int new_lx = lx, new_rx = rx;
    int new_ly = ly, new_ry = ry;

    for (int x : {x1, x2, x3}) {
        int res = query(x, y);

        new_lx = std::max(new_lx, x - res);
        new_rx = std::min(new_rx, x + res);

        new_ly = std::max(new_ly, y - res);
        new_ry = std::min(new_ry, y + res);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r_x = lx + i, r_y = ly + j;

                int dx = abs(r_x - x);
                int dy = abs(r_y - y);

                int d = dx + dy;
                int S = (dx + 1) * (dy + 1);

                if (res < d || d + S < res) {
                    good[i][j] = false;
                }
            }
        }
    }

    bool has_good = false;
    for (auto vx : good) {
        for (auto vy : vx) {
            if (vy) {
                has_good = true;
            }
        }
    }
    good.clear();
    good.shrink_to_fit();

    if (has_good) {
        f(new_lx, new_rx, new_ly, new_ry);
    } else {
        f(lx, rx, ly + m, ry);
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    ans_x = 0;
    ans_y = 0;
    cnt_q = 0;

    f(1, m, 1, n);

    std::cout << "! " << ans_y << ' ' << ans_x << '\n';
    std::cout.flush();
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
