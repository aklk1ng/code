#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int sx, int sy, std::vector<std::vector<int>> &d,
         std::vector<std::vector<int>> &a) {
    int n = d.size();
    int m = d[0].size();
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dd) {
            int tx = x + dx;
            int ty = y + dy;
            if (tx >= 0 && ty >= 0 && tx < n && ty < m && d[tx][ty] == 0 &&
                a[tx][ty] != -1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (auto &e : d) {
        for (auto &i : e) {
            i--;
        }
    }
}

void solve() {
    int n, m, w;
    std::cin >> n >> m >> w;
    std::vector<std::vector<int>> a(n, std::vector<int>(m)),
        d1(n, std::vector<int>(m)), d2(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    bfs(0, 0, d1, a);
    bfs(n - 1, m - 1, d2, a);
    ll best = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d2[i][j] != -1 && a[i][j] >= 1) {
                best = std::min(best, a[i][j] + w * 1LL * d2[i][j]);
            }
        }
    }
    ll ans = w * 1LL * d1[n - 1][m - 1];
    if (d1[n - 1][m - 1] == -1) {
        ans = 1e18;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d1[i][j] != -1 && a[i][j] >= 1 && best != 1e18) {
                ans = std::min(ans, w * 1ll * d1[i][j] + a[i][j] + best);
            }
        }
    }
    if (ans == 1e18) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << '\n';
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
