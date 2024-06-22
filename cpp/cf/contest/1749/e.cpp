#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (auto &it : s) {
        std::cin >> it;
    }

    auto in = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

    auto can = [&](int x, int y) {
        if (!in(x, y)) {
            return false;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (in(nx, ny) && s[nx][ny] == '#') {
                return false;
            }
        }
        return true;
    };

    std::vector d(n, std::vector<int>(m, 1e9)), p(n, std::vector<int>(m));
    std::deque<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == '#') {
            d[i][0] = 0;
            q.push_front({i, 0});
        } else if (can(i, 0)) {
            d[i][0] = 1;
            q.push_back({i, 0});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int i = 4; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!can(nx, ny)) {
                continue;
            }
            int w = (s[nx][ny] != '#');
            if (d[nx][ny] > d[x][y] + w) {
                d[nx][ny] = d[x][y] + w;
                p[nx][ny] = i;
                if (w) {
                    q.push_back({nx, ny});
                } else {
                    q.push_front({nx, ny});
                }
            }
        }
    }

    int x = 0, y = m - 1;
    for (int i = 0; i < n; ++i) {
        if (d[x][y] > d[i][y]) {
            x = i;
        }
    }
    if (d[x][y] == 1e9) {
        std::cout << "NO\n";
        return;
    }
    while (true) {
        s[x][y] = '#';
        int i = p[x][y];
        if (!i) {
            break;
        }
        x -= dx[i];
        y -= dy[i];
    }
    std::cout << "YES\n";
    for (auto it : s) {
        std::cout << it << '\n';
    }
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
