#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 105;

void solve() {
    int n, m, k, q;
    std::cin >> n >> m >> k >> q;
    std::string s;
    std::cin >> s;

    s = ' ' + s;

    char op;
    std::vector grid(N, std::vector<int>(N));
    auto calSum = [&](int x1, int y1, int x2, int y2) {
        int sum = 0;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                sum += grid[i][j];
            }
        }
        return sum;
    };
    auto Op = [&](int x, int y) {
        std::cout << x << ' ' << y << '\n';
        for (int i = 1; i <= k; i++) {
            grid[x][y] = 1;
            if (op == 'H') {
                y++;
            } else {
                x++;
            }
        }
        std::vector<int> rowSums(n + 1), colSums(m + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (rowSums[i] == m || colSums[j] == n) {
                    grid[i][j] = 0;
                }
            }
        }
    };
    for (int i = 1; i <= q; i++) {
        op = s[i];
        if (op == 'H') {
            int row = -1;
            for (int j = 1; j <= n; j++)
                if (calSum(j, 1, j, k) == 0) {
                    row = j;
                    if (calSum(j, 1, j, m) == m - k) {
                        break;
                    }
                }
            Op(row, 1);
        } else {
            int col = -1;
            for (int j = 1; j <= m; j++)
                if (calSum(1, j, k, j) == 0) {
                    col = j;
                    if (calSum(1, j, n, j) == n - k) {
                        break;
                    }
                }
            Op(1, col);
        }
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
